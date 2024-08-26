#!/bin/bash

clear
echo "Sikraken regression testing: starting script run_regression.sh "

# Check if the directory argument is provided
if [ -z "$1" ]; then
    echo "Sikraken regression testing ERROR: script usage is $0 <directory_of_regression_c_files>"
    exit 1
fi

# Set the directory containing the .c files from the argument
c_files_directory="$1"

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

# Loop over all .c files in the directory
for regression_test_file in "$c_files_directory"/*.c; do

    # Extract the base name of the file (without the path and extension)
    base_name=$(basename "$regression_test_file" .c)
    config_file="$c_files_directory"/"$base_name".json

    # Check if the configuration file exists
    if [ ! -f "$config_file" ]; then
        echo "Sikraken regression testing ERROR: Configuration file $config_file does not exist"
        exit 1
    fi

    #preprocess using gcc and parse using Sikraken's parser the regression test
    ./bin/call_parser.sh $c_files_directory "$base_name".c
    if [ $? -ne 0 ]; then
        echo "Sikraken regression testing ERROR: Sikraken parsing of $regression_test_file failed"
        exit 1
    else
        echo "Sikraken successfully parsed $regression_test_file"
    fi

    # Loop over all configurations in the configuration file
    config_count=$(jq '.configurations | length' "$config_file")

    for i in $(seq 0 $((config_count - 1))); do
        # Extract the configuration data
        config=$(jq ".configurations[$i]" "$config_file")

        id=$(echo "$config" | jq -r '.id')
        description=$(echo "$config" | jq -r '.description')
        restarts=$(echo "$config" | jq -r '.restarts')
        tries=$(echo "$config" | jq -r '.tries')
        expected_run_time=$(echo "$config" | jq -r '.expected_run_time')
        expected_test_inputs_number=$(echo "$config" | jq -r '.expected_test_inputs_number')
        expected_coverage=$(echo "$config" | jq -r '.expected_coverage')

        #generate test inputs
        eclipse -f ./SymbolicExecutor/se_main.pl -e "se_main(['/home/chris/Sikraken/', '"$c_files_directory"/', '"$base_name"', main, release, testcomp, $restarts, $tries])"
        if [ $? -ne 0 ]; then
            echo "Sikraken regression testing ERROR: test inputs generation of $regression_test_file failed"
            exit 1
        else
            echo "Sikraken generated test inputs for $regression_test_file in $id configuration"
        fi

        #validate test inputs
        testcov --no-isolation --test-suite "$c_files_directory""/suite-""$base_name"".zip" "$regression_test_file"
        if [ $? -ne 0 ]; then
            echo "Sikraken regression testing ERROR: TestCov test inputs validation of $regression_test_file failed"
            exit 1
        else
            echo "TestCov validated the test inputs for $regression_test_file in $id configuration"    
        fi
    done
done

echo "Sikraken regression testing script run_regression.sh has terminated successfully."