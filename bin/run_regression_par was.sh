#!/bin/bash
#
# Script: run_regression_par.sh
# Author: Chris Meudec
# Date: May 2025 (Updated Oct 2025 for parallel error handling)
# Description: This script runs Sikraken regression tests in parallel on C files in a specified directory (usually Sikraken/regression_tests).
# It should behave similarly to run_regression.sh but it runs the test generation in parallel.
# TestCov is run sequentially at the end because it does not support parallel execution.
# Usage: ./bin/run_regression_par.sh <number_of_cores> <relative_directory_of_regression_c_files> [-scg] [-d]
# Example: ./bin/run_regression_par.sh 4 regression_tests

clear
echo "PARALLEL Regression Testing"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

script_name=$(basename "$0")

# --- GLOBAL ERROR FLAG FOR PARALLEL EXECUTION ---
PARALLEL_FAIL_FLAG="$SIKRAKEN_INSTALL_DIR/parallel_fail.log"

# --- Usage check ---
if [ $# -lt 2 ] || [ $# -gt 4 ]; then
    echo "Sikraken PARALLEL regression testing ERROR:"
    echo "Usage: $script_name <number_of_cores> <relative_directory_of_regression_c_files> [-scg] [-d]"
    echo "Example: $script_name 8 regression_tests true -d"
    exit 1
fi

# --- Core arguments ---
max_jobs=$1
rel_path_c_file="$2"
c_files_directory="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"

# --- Defaults ---
shortcutgen=""
debug_mode="release"

# --- Parse optional args ---
shift 2
while [ $# -gt 0 ]; do
    case "$1" in
        -scg)
            shortcutgen=", shortcut_gen"
            ;;
        -d)
            debug_mode="debug"
            ;;
        *)
            echo "Unknown option: $1"
            echo "Usage: $script_name <number_of_cores> <relative_directory_of_regression_c_files> [shortcutgen] [-d]"
            exit 1
            ;;
    esac
    shift
done

# --- Debug info ---
echo "max_jobs     = $max_jobs"
echo "c_files_dir  = $c_files_directory"
echo "shortcutgen  = $shortcutgen"
echo "mode         = $debug_mode"

# Check if the provided directory exists
if [ ! -d "$c_files_directory" ]; then
    echo "Sikraken regression testing ERROR: the passed directory of regression files $c_files_directory does not exist."
    exit 1
fi

# Re-compile the parser in case it changed during development
./bin/compile_parser.sh
if [ $? -ne 0 ]; then
    echo "Sikraken regression testing ERROR: Sikraken parser recompilation failed"
    exit 1
else
    echo "Sikraken parser successfully recompiled"
fi

if [ -f regression_tests_run.log ]; then
    rm -f regression_tests_run.log
fi
# --- CLEANUP GLOBAL FAILURE FLAG ---
if [ -f "$PARALLEL_FAIL_FLAG" ]; then
    rm -f "$PARALLEL_FAIL_FLAG"
fi

# Job pool to limit the number of background processes
job_pool() {
    while [ "$(jobs -r | wc -l)" -ge "$max_jobs" ]; do
        sleep 1  # Wait for an available slot
    done
}

# NOTE: The return code from this function is the exit status of the subshell (background process)
# It does NOT terminate the main script, so errors are written to PARALLEL_FAIL_FLAG instead.
generate_tests() {
    local regression_test_file="$1"
    
    # Extract the base name of the file (without the path nor extension)
    local base_name=$(basename "$regression_test_file" .c)
    local config_file="$c_files_directory"/"$base_name".json
    local yml_file="$c_files_directory"/"$base_name".yml

    # Check if our configuration file exists
    if [ ! -f "$config_file" ]; then
        echo "Sikraken ERROR from $script_name: Configuration file $config_file does not exist" >> "$PARALLEL_FAIL_FLAG"
        return 1
    fi

    # Check if the testcomp yml file exists
    local data_model
    if [ ! -f "$yml_file" ]; then
        echo "Sikraken $script_name WARNING: .yml file $yml_file does not exist, assuming ILP32"
        data_model="ILP32"
    else
        data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')
    fi

    # Generate GCC flag based on the value of data_model
    local gcc_flag
    if [ "$data_model" == "ILP32" ]; then
        gcc_flag="-m32"
    elif [ "$data_model" == "LP64" ]; then
        gcc_flag="-m64"
    else
        echo "Sikraken ERROR from $script_name: Unsupported data model: $data_model" >> "$PARALLEL_FAIL_FLAG"
        return 1
    fi

    # Preprocess the regression test using gcc and parse using Sikraken's parser
    call_parser="$SIKRAKEN_INSTALL_DIR/bin/call_parser.sh $rel_path_c_file/$base_name.c $gcc_flag"
    $call_parser
    if [ $? -ne 0 ]; then
        echo "Sikraken ERROR from $script_name: Sikraken parsing of $regression_test_file failed using $call_parser" >> "$PARALLEL_FAIL_FLAG"
        return 1
    else
        echo "Sikraken $script_name log: parsed $regression_test_file"
    fi

    # Loop over all configurations in the configuration file
    local config_count=$(jq '.configurations | length' "$config_file")

    for i in $(seq 0 $((config_count - 1))); do
        # Extract configuration data
        local config=$(jq ".configurations[$i]" "$config_file")

        local algo=$(echo "$config" | jq -r '.algo')

        echo -e "\e[34mGenerating tests for $regression_test_file using algo: $algo\e[0m"
        local log_file="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/sikraken.log" 
        # Generate test inputs
        local eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$SIKRAKEN_INSTALL_DIR/$rel_path_c_file', '$base_name', main, $debug_mode, testcomp, '$gcc_flag', $algo $shortcutgen])"
        $SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call" >> $log_file 2>&1
        if [ $? -ne 0 ]; then
            # THIS IS THE CRITICAL CHANGE: Log the error to a file and return 
            echo "Sikraken ERROR from $script_name: Call to ECLiPSe $eclipse_call failed for $regression_test_file" >> "$PARALLEL_FAIL_FLAG"
            return 1
        else
            echo "Sikraken $script_name log: Test inputs generated for $regression_test_file in configuration $i"
        fi
        #call_testcov "$regression_test_file" #cannot do this testcov needs to be run sequentially
    done
}

call_testcov() {
    local regression_test_file="$1"
    echo "calling test cov for $regression_test_file"
        
    # Extract the base name of the file (without the path nor extension)
    local base_name=$(basename "$regression_test_file" .c)
    local config_file="$c_files_directory"/"$base_name".json
    local yml_file="$c_files_directory"/"$base_name".yml

    # Check if the testcomp yml file exists
    local data_model
    if [ ! -f "$yml_file" ]; then
        echo "Sikraken $script_name log: .yml file $yml_file does not exist, assuming ILP32"
        data_model="ILP32"
    else
        data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')
    fi

    # Generate GCC flag based on the value of data_model
    local testcov_data_model
    if [ "$data_model" == "ILP32" ]; then
        testcov_data_model="-32"
    elif [ "$data_model" == "LP64" ]; then
        testcov_data_model="-64"
    fi

    # Loop over all configurations in the configuration file
    local config_count=$(jq '.configurations | length' "$config_file")

    for i in $(seq 0 $((config_count - 1))); do
        # Extract configuration data
        local config=$(jq ".configurations[$i]" "$config_file")

        local expected_test_inputs_number=$(echo "$config" | jq -r '.expected_test_inputs_number')
        local expected_coverage=$(echo "$config" | jq -r '.expected_coverage')

        testcov_call="./bin/run_testcov.sh $regression_test_file $testcov_data_model"
        echo "CALL TO TESTCOV IS $testcov_call"
        local testcov_output=$($testcov_call 2>&1)
        if [ $? -ne 0 ]; then
            echo "Sikraken ERROR from $script_name: TestCov validation failed for $regression_test_file"
            exit 1 # This is safe because this function is run sequentially, not in the background
        fi

        # get the number of test run and coverage achieved from testcov output
        local tests_nb_line=$(echo "$testcov_output" | grep "Tests run:")
        local test_nb_value=$(echo "$tests_nb_line" | awk '{print $3}')
        local coverage_line=$(echo "$testcov_output" | grep "Coverage:")
        local coverage_value=$(echo "$coverage_line" | awk '{print $2}' | sed 's/%//')

        echo "Tests log: $test_nb_value ($expected_test_inputs_number expected), Coverage: $coverage_value% ($expected_coverage% expected)"

        if [ "$test_nb_value" -eq 0 ]; then
            echo -e "\e[31mERROR: No tests generated for $regression_test_file in configuration $i.\e[0m"
            exit 1
        fi

        if [ "$expected_test_inputs_number" != "$test_nb_value"  ]; then
            echo "Warning: Tests generation mismatch! For $regression_test_file in configuration $i, expected: $expected_test_inputs_number, but got: $test_nb_value." >> regression_tests_run.log
        fi

        if [ "$expected_coverage" != "$coverage_value" ]; then
            echo "Warning: Coverage mismatch! For $regression_test_file in configuration $i, expected: $expected_coverage, but got: $coverage_value." >> regression_tests_run.log
        fi
    done
}

### main starts here

# Loop over all .c files and process them in parallel
for regression_test_file in "$c_files_directory"/*.c; do
    job_pool  # Wait for an available slot
    generate_tests "$regression_test_file" &  # Run in the background
done

wait    # Wait for all background jobs to finish

# --- CHECK FOR PARALLEL ERRORS HERE ---
if [ -f "$PARALLEL_FAIL_FLAG" ]; then
    echo -e "\n\e[31m--- PARALLEL GENERATION FAILED ---\e[0m"
    echo "One or more parallel jobs failed. Errors captured in $PARALLEL_FAIL_FLAG:"
    cat "$PARALLEL_FAIL_FLAG"
    rm -f "$PARALLEL_FAIL_FLAG" # Clean up the flag file
    exit 1 # Terminate the main script here
fi

# Run testcov sequentially (only if parallel generation succeeded)
for regression_test_file in "$c_files_directory"/*.c; do
    call_testcov "$regression_test_file"
done

if [ -f regression_tests_run.log ]; then
    echo -e "\e[31mSikraken regression testing script run_regression.sh has terminated with warnings.\e[0m"
    cat regression_tests_run.log
else
    echo -e "\e[32mSikraken regression testing script run_regression.sh has terminated successfully.\e[0m"
fi
