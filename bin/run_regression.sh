#!/bin/bash
#
# Script: run_regression.sh
# Author: Chris Meudec  
# Date: May 2025
# Description: This script runs Sikraken regression tests on C files in a specified directory (usually Sikraken/regression_tests).
# It first recompiles the Sikraken parser everytime, then processes each C file in the directory.
# For each file C file foo.c it reads from the corresponding configuration file foo.json describing the test generation configuration.
# If it exists, foo.yml is also read to determine the data model (ILP32 or LP64).
# foo.c is then preprocessed using gcc and the Sikraken parser is called.
# Eclipse is then called to generate test inputs.
# Then TestCov is called to measure the coverage achieved.
# Finally, the script compares the expected behaviour of the test generation process (described in foo.json) with the actual behaviour.
# A log file is created to store the results of the regerssion test
# Usage: ./bin/run_regression.sh <relative_directory_of_regression_c_files>
# Example: ./bin/run_regression.sh regression_tests

clear
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "Sikraken $0 log: SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

# Check if the directory argument is provided
if [ -z "$1" ]; then
    echo "Sikraken ERROR from $0: script usage is $0 <relative_directory_of_regression_c_files> e.g. regression_tests"
    exit 1
fi

# Set the directory containing the .c files from the argument
rel_path_c_file="$1"
c_files_directory="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"    #e.g. /home/chris/Sikraken/regression_tests

# Check if the provided directory exists
if [ ! -d "$c_files_directory" ]; then
    echo "Sikraken ERROR from $0: the passed directory of regression files $c_files_directory does not exist."
    exit 1
fi

# re-compile the parser in case it changed during development
./bin/compile_parser.sh
if [ $? -ne 0 ]; then
    echo "Sikraken ERROR from $0: Sikraken parser recompilation failed"
    exit 1
else
    echo "Sikraken $0 log: parser successfully recompiled"
fi

log_file="regression_tests_run.log"
if [ -f $log_file ]; then
    rm -f $log_file
fi

# Loop over all .c files in the directory
for regression_test_file in "$c_files_directory"/*.c; do

    # Extract the base name of the file (without the path nor extension)
    base_name=$(basename "$regression_test_file" .c)
    config_file="$c_files_directory"/"$base_name".json
    yml_file="$c_files_directory"/"$base_name".yml

    # Check if our configuration file exists
    if [ ! -f "$config_file" ]; then
        echo "Sikraken ERROR from $0: Configuration file $config_file does not exist"
        exit 1
    fi

    # Check if the testcomp yml file exists
    if [ ! -f "$yml_file" ]; then
        echo "Sikraken $0 log: .yml file $yml_file does not exist, assuming ILP32"
        data_model="ILP32"
    else
        data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')
    fi

    # Generate GCC flag based on the value of data_model
    if [ "$data_model" == "ILP32" ]; then
        gcc_flag="-m32"
        testcov_data_model="-32"
    elif [ "$data_model" == "LP64" ]; then
        gcc_flag="-m64"
        testcov_data_model="-64"
    else
        echo "Sikraken ERROR from $0: Unsupported data model: $data_model"
        exit 1
    fi

    #preprocess the regression test using gcc and parse using Sikraken's parser
    call_parser="$SIKRAKEN_INSTALL_DIR/bin/call_parser.sh $rel_path_c_file/$base_name.c $gcc_flag"
    $call_parser
    if [ $? -ne 0 ]; then
        echo "Sikraken ERROR from $0: Sikraken parsing of $regression_test_file failed using $call_parser"
        exit 1
    else
        echo "Sikraken $0 log: parsed $regression_test_file"
    fi

    # Loop over all configurations in the configuration file
    config_count=$(jq '.configurations | length' "$config_file")

    for i in $(seq 0 $((config_count - 1))); do
        # Extract the configuration data
        config=$(jq ".configurations[$i]" "$config_file")

        id=$(echo "$config" | jq -r '.id')
        description=$(echo "$config" | jq -r '.description')
        algo=$(echo "$config" | jq -r '.algo')
        #restarts=$(echo "$config" | jq -r '.restarts')
        #tries=$(echo "$config" | jq -r '.tries')
        expected_run_time=$(echo "$config" | jq -r '.expected_run_time')
        expected_test_inputs_number=$(echo "$config" | jq -r '.expected_test_inputs_number')
        expected_coverage=$(echo "$config" | jq -r '.expected_coverage')

        echo -e "\e[34mSikraken $0 log: now generating tests for $regression_test_file in $id configuration.\e[0m"

        #generate test inputs
        eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$SIKRAKEN_INSTALL_DIR/$rel_path_c_file', '$base_name', main, debug, testcomp, '$gcc_flag', $algo])"
        $SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call"
        if [ $? -ne 0 ]; then
            echo "Sikraken ERROR from $0: call to ECLiPSe $eclipse_call failed"
            exit 1
        else
            echo "Sikraken $0 log: generated test inputs for $regression_test_file in $id configuration"
        fi

        #validate test inputs
        #testcov_output=$(testcov $testcov_data_model --no-isolation --test-suite "$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/test-suite.zip" "$regression_test_file")
        testcov_output=$($SIKRAKEN_INSTALL_DIR/bin/run_testcov.sh $regression_test_file $testcov_data_model)
        if [ $? -ne 0 ]; then
            echo "Sikraken ERROR from $0: TestCov test inputs validation of $regression_test_file failed"
            exit 1
        else
            echo "Sikraken $0 log: TestCov validated the test inputs for $regression_test_file in $id configuration"    
        fi

        tests_nb_line=$(echo "$testcov_output" | grep "Tests run:")
        test_nb_value=$(echo "$tests_nb_line" | awk '{print $3}')
        echo "Sikraken $0 log: Number of tests is: $test_nb_value ($expected_test_inputs_number expected)"
        coverage_line=$(echo "$testcov_output" | grep "Coverage:")
        coverage_value=$(echo "$coverage_line" | awk '{print $2}')
        coverage_value=$(echo "$coverage_value" | sed 's/%//')
        echo "Sikraken $0 log: Coverage is: $coverage_value ($expected_coverage expected)"

        if [ $expected_test_inputs_number != $test_nb_value ]; then
            echo "Sikraken $0 warning: Tests number generation mismatch! For $regression_test_file in $id configuration, expected: $expected_test_inputs_number, but got: $test_nb_value when running: $eclipse_call." >> $log_file
        fi

        if [ "$expected_coverage" != "$coverage_value" ]; then
            echo "Sikraken $0 warning: Coverage mismatch! For $regression_test_file in $id configuration, expected: $expected_coverage, but got: $coverage_value when running: $eclipse_call." >> $log_file
        fi
    done
done

if [ -f $log_file ]; then
    echo -e "\e[31mSikraken $0 log: Sikraken regression testing has terminated with warnings.\e[0m"
    cat $log_file
else
    echo -e "\e[32mSikraken $0 log: Sikraken regression testing has terminated successfully.\e[0m"
fi