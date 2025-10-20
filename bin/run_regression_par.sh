#!/bin/bash
#
# Script: run_regression_par.sh
# Author: Chris Meudec
# Date: May 2025 (Updated Oct 2025 for parallel error handling and final summary)
# Description: Runs Sikraken regression tests in parallel, then sequential TestCov validation.
# Usage: ./bin/run_regression_par.sh <number_of_cores> <relative_directory_of_regression_c_files> [-scg] [-d]

clear
echo "PARALLEL Regression Testing"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" # Script directory
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

script_name=$(basename "$0")

# --- GLOBAL ERROR FLAG ---
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

# Check directory existence
if [ ! -d "$c_files_directory" ]; then
    echo "Sikraken regression testing ERROR: the passed directory of regression files $c_files_directory does not exist."
    exit 1
fi

# Recompile parser
./bin/compile_parser.sh
if [ $? -ne 0 ]; then
    echo "Sikraken regression testing ERROR: Sikraken parser recompilation failed"
    exit 1
else
    echo "Sikraken parser successfully recompiled"
fi

[ -f regression_tests_run.log ] && rm -f regression_tests_run.log
[ -f "$PARALLEL_FAIL_FLAG" ] && rm -f "$PARALLEL_FAIL_FLAG"

# --- Job pool ---
job_pool() {
    while [ "$(jobs -r | wc -l)" -ge "$max_jobs" ]; do
        sleep 1
    done
}

# --- Generate tests in parallel ---
generate_tests() {
    local regression_test_file="$1"
    local base_name=$(basename "$regression_test_file" .c)
    local config_file="$c_files_directory/$base_name.json"
    local yml_file="$c_files_directory/$base_name.yml"

    [ ! -f "$config_file" ] && echo "Sikraken ERROR: Configuration $config_file missing" >> "$PARALLEL_FAIL_FLAG" && return 1

    # Determine data model
    local data_model="ILP32"
    [ -f "$yml_file" ] && data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')

    local gcc_flag
    case "$data_model" in
        ILP32) gcc_flag="-m32";;
        LP64) gcc_flag="-m64";;
        *) echo "Sikraken ERROR: Unsupported data model $data_model" >> "$PARALLEL_FAIL_FLAG"; return 1;;
    esac

    # Call parser
    call_parser="$SIKRAKEN_INSTALL_DIR/bin/call_parser.sh $rel_path_c_file/$base_name.c $gcc_flag"
    $call_parser
    if [ $? -ne 0 ]; then
        echo "Sikraken ERROR: Parsing $regression_test_file failed" >> "$PARALLEL_FAIL_FLAG"
        return 1
    fi

    # Loop over configurations
    local config_count=$(jq '.configurations | length' "$config_file")
    for i in $(seq 0 $((config_count - 1))); do
        local config=$(jq ".configurations[$i]" "$config_file")
        local algo=$(echo "$config" | jq -r '.algo')

        echo -e "\e[34mGenerating tests for $regression_test_file using algo: $algo\e[0m"
        local log_file="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/sikraken.log"
        local eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$SIKRAKEN_INSTALL_DIR/$rel_path_c_file', '$base_name', main, $debug_mode, testcomp, '$gcc_flag', $algo $shortcutgen])"
        $SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call" >> $log_file 2>&1
        [ $? -ne 0 ] && echo "Sikraken ERROR: ECLiPSe call failed for $regression_test_file" >> "$PARALLEL_FAIL_FLAG" && return 1
    done
}

# --- Call TestCov sequentially and log output ---
call_testcov() {
    local regression_test_file="$1"
    local base_name=$(basename "$regression_test_file" .c)
    local yml_file="$c_files_directory/$base_name.yml"
    local data_model="ILP32"
    [ -f "$yml_file" ] && data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')
    local testcov_data_model
    case "$data_model" in
        ILP32) testcov_data_model="-32";;
        LP64) testcov_data_model="-64";;
    esac

    # Ensure testcov folder exists
    local testcov_dir="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/testcov"
    mkdir -p "$testcov_dir"
    local testcov_log="$testcov_dir/testcov_call.log"

    local testcov_call="./bin/run_testcov.sh $regression_test_file $testcov_data_model"
    $testcov_call > "$testcov_log" 2>&1
    [ $? -ne 0 ] && echo "Sikraken ERROR: TestCov failed for $regression_test_file" && exit 1
}

# --- MAIN EXECUTION ---

# Run Sikraken in parallel
for regression_test_file in "$c_files_directory"/*.c; do
    job_pool
    generate_tests "$regression_test_file" &
done
wait

# Check for parallel errors
if [ -f "$PARALLEL_FAIL_FLAG" ]; then
    echo -e "\n\e[31m--- PARALLEL GENERATION FAILED ---\e[0m"
    cat "$PARALLEL_FAIL_FLAG"
    rm -f "$PARALLEL_FAIL_FLAG"
    exit 1
fi

# Run TestCov sequentially
for regression_test_file in "$c_files_directory"/*.c; do
    call_testcov "$regression_test_file"
done

# --- FINAL SUMMARY WITH EXPECTED VS ACTUAL ---
echo -e "\n================ FINAL SUMMARY ================\n"

for regression_test_file in "$c_files_directory"/*.c; do
    base_name=$(basename "$regression_test_file" .c)
    sikraken_log="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/sikraken.log"
    testcov_log="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/testcov/testcov_call.log"
    config_file="$c_files_directory/$base_name.json"

    # Parse Sikraken log
    if [ -f "$sikraken_log" ]; then
        sik_tests=$(grep "Generated:" "$sikraken_log" | awk '{print $2}' | tail -1)
        sik_edges=$(grep "CFG:" "$sikraken_log" | awk '{print $2}' | tail -1)
        sik_cov=$(grep "Coverage:" "$sikraken_log" | awk '{print $2}' | sed 's/%//' | tail -1)
    else
        sik_tests="NA"; sik_edges="NA"; sik_cov="NA"
    fi

    # Parse TestCov log
    if [ -f "$testcov_log" ]; then
        tc_tests=$(grep "Tests run:" "$testcov_log" | awk '{print $3}' | tail -1)
        tc_goals=$(grep "Number of goals:" "$testcov_log" | awk '{print $4}' | tail -1)
        tc_cov=$(grep "Coverage:" "$testcov_log" | awk '{print $2}' | sed 's/%//' | tail -1)
    else
        tc_tests="NA"; tc_goals="NA"; tc_cov="NA"
    fi

    # Get expected tests and coverage from JSON (first configuration)
    if [ -f "$config_file" ]; then
        expected_test_inputs_number=$(jq -r '.configurations[0].expected_test_inputs_number' "$config_file")
        expected_coverage=$(jq -r '.configurations[0].expected_coverage' "$config_file")
    else
        expected_test_inputs_number="NA"
        expected_coverage="NA"
    fi

    # Print summary line
    echo "$base_name.c → Sikraken: $sik_edges edges / $sik_cov% ($sik_tests tests), expected: $expected_test_inputs_number / $expected_coverage%  |  TestCov: $tc_goals goals / $tc_cov% ($tc_tests tests)"

    # Log warnings if mismatch
    if [ "$sik_tests" != "$expected_test_inputs_number" ]; then
        echo "Warning: Sikraken tests mismatch for $base_name.c: expected $expected_test_inputs_number, got $sik_tests" >> regression_tests_run.log
    fi
    # Convert coverage strings to numbers (strip trailing %)
    sik_cov_num=$(echo "$sik_cov" | sed 's/%//')
    expected_cov_num=$(echo "$expected_coverage" | sed 's/%//')

    # Numeric comparison
    awk -v a="$sik_cov_num" -v b="$expected_cov_num" 'BEGIN{if(a!=b) exit 1; else exit 0}'
    if [ $? -ne 0 ]; then
        echo "Warning: Sikraken coverage mismatch for $base_name.c: expected $expected_coverage%, got $sik_cov%" >> regression_tests_run.log
    fi
done

# --- End message ---
if [ -f regression_tests_run.log ]; then
    echo -e "\n\e[31mSikraken regression testing script run_regression_par.sh terminated with warnings.\e[0m"
    cat regression_tests_run.log
else
    echo -e "\n\e[32mSikraken regression testing script run_regression_par.sh terminated successfully.\e[0m"
fi
