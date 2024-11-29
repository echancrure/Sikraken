#!/bin/bash

clear
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "Sikraken regression testing run_regression.sh says: SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

# Check if the directory argument is provided
if [ -z "$1" ]; then
    echo "Sikraken regression testing ERROR: script usage is $0 <relative_directory_of_regression_c_files> e.g. regression_tests"
    exit 1
fi

# Set the directory containing the .c files from the argument
rel_path_c_file="$1"
c_files_directory="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"    #e.g. /home/chris/Sikraken/regression_tests

# Check if the provided directory exists
if [ ! -d "$c_files_directory" ]; then
    echo "Sikraken regression testing ERROR: the passed directory of regression files $c_files_directory does not exist."
    exit 1
fi

# re-compile the parser in case it changed during development
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

# Maximum number of concurrent jobs
max_jobs=4

# Job pool to limit the number of background processes
job_pool() {
    while [ "$(jobs -r | wc -l)" -ge "$max_jobs" ]; do
        sleep 1  # Wait for an available slot
    done
}

# Function to process each .c file
process_file() {
    local regression_test_file="$1"
    
    # Extract the base name of the file (without the path nor extension)
    local base_name=$(basename "$regression_test_file" .c)
    local config_file="$c_files_directory"/"$base_name".json
    local yml_file="$c_files_directory"/"$base_name".yml

    # Check if our configuration file exists
    if [ ! -f "$config_file" ]; then
        echo "Sikraken regression testing ERROR: Configuration file $config_file does not exist"
        return 1
    fi

    # Check if the testcomp yml file exists
    local data_model
    if [ ! -f "$yml_file" ]; then
        echo "Sikraken regression testing WARNING: .yml file $yml_file does not exist, assuming ILP32"
        data_model="ILP32"
    else
        data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')
    fi

    # Generate GCC flag based on the value of data_model
    local gcc_flag testcov_data_model
    if [ "$data_model" == "ILP32" ]; then
        gcc_flag="-m32"
        testcov_data_model="-32"
    elif [ "$data_model" == "LP64" ]; then
        gcc_flag="-m64"
        testcov_data_model="-64"
    else
        echo "Sikraken regression testing ERROR: Unsupported data model: $data_model"
        return 1
    fi

    # Preprocess the regression test using gcc and parse using Sikraken's parser
    $SIKRAKEN_INSTALL_DIR/bin/call_parser.sh "$SIKRAKEN_INSTALL_DIR/$rel_path_c_file" "$base_name" "$gcc_flag"
    if [ $? -ne 0 ]; then
        echo "Sikraken regression testing ERROR: Parsing of $regression_test_file failed"
        return 1
    else
        echo "Sikraken successfully parsed $regression_test_file"
    fi

    # Loop over all configurations in the configuration file
    local config_count=$(jq '.configurations | length' "$config_file")

    for i in $(seq 0 $((config_count - 1))); do
        # Extract configuration data
        local config=$(jq ".configurations[$i]" "$config_file")

        local id=$(echo "$config" | jq -r '.id')
        local algo=$(echo "$config" | jq -r '.algo')
        local expected_test_inputs_number=$(echo "$config" | jq -r '.expected_test_inputs_number')
        local expected_coverage=$(echo "$config" | jq -r '.expected_coverage')

        echo -e "\e[34mGenerating tests for $regression_test_file in $id configuration.\e[0m"

        # Generate test inputs
        local eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$SIKRAKEN_INSTALL_DIR/$rel_path_c_file', '$base_name', main, debug, testcomp, '$gcc_flag', $algo])"
        $SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call"
        if [ $? -ne 0 ]; then
            echo "ERROR: Call to ECLiPSe $eclipse_call failed"
            return 1
        else
            echo "Test inputs generated for $regression_test_file in $id configuration"
        fi

        # Validate test inputs
        # local testcov_output=$($SIKRAKEN_INSTALL_DIR/bin/run_testcov.sh "$regression_test_file" "$testcov_data_model")
        zipfile="./sikraken_output/$base_name/test-suite.zip"
        rm -f $zipfile
        zip -r $zipfile "./sikraken_output/$base_name/test-suite"
        local testcov_output=$(testcov --no-isolation $testcov_data_model --test-suite $zipfile $rel_path_c_file --output "./sikraken_output/$base_name/testcov")
        #local testcov_output=$($SIKRAKEN_INSTALL_DIR/bin/run_testcov.sh "$regression_test_file" "$testcov_data_model")
        if [ $? -ne 0 ]; then
            echo "ERROR: TestCov validation failed for $regression_test_file"
            return 1
        fi

        # Process and check results
        local tests_nb_line=$(echo "$testcov_output" | grep "Tests run:")
        local test_nb_value=$(echo "$tests_nb_line" | awk '{print $3}')
        local coverage_line=$(echo "$testcov_output" | grep "Coverage:")
        local coverage_value=$(echo "$coverage_line" | awk '{print $2}' | sed 's/%//')

        echo "Tests: $test_nb_value ($expected_test_inputs_number expected), Coverage: $coverage_value% ($expected_coverage% expected)"

        if [ "$expected_test_inputs_number" != "$test_nb_value" ]; then
            echo "Error: Test count mismatch for $regression_test_file in $id configuration." >> regression_tests_run.log
        fi

        if [ "$expected_coverage" != "$coverage_value" ]; then
            echo "Error: Coverage mismatch for $regression_test_file in $id configuration." >> regression_tests_run.log
        fi
    done
}

# Loop over all .c files and process them in parallel
for regression_test_file in "$c_files_directory"/*.c; do
    job_pool  # Wait for an available slot
    process_file "$regression_test_file" &  # Run in the background
done

# Wait for all background jobs to finish
wait

if [ -f regression_tests_run.log ]; then
    echo -e "\e[31mSikraken regression testing script run_regression.sh has terminated with warnings.\e[0m"
    cat regression_tests_run.log
else
    echo -e "\e[32mSikraken regression testing script run_regression.sh has terminated successfully.\e[0m"
fi