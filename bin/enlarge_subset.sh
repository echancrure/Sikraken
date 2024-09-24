#!/bin/bash

clear
echo "ENLARGE subset: crash and learn"

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
    yml_file="$c_files_directory"/"$base_name".yml

    # Check if the testcomp yml file exists
    if [ ! -f "$yml_file" ]; then
        echo "Sikraken regression testing WARNING: .yml file $yml_file does not exist, assuming ILP32"
        data_model="ILP32"
    else
        data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')
    fi

    # Generate GCC flag based on the value of data_model
    if [ "$data_model" == "ILP32" ]; then
        gcc_flag="-m32"
        testcov_data_model="-32"
    elif [ "$data_model" == "ILP64" ]; then
        gcc_flag="-m64"
        testcov_data_model="-64"
    else
        echo "Sikraken regression testing ERROR: Unsupported data model: $data_model"
        exit 1
    fi

    #preprocess the regression test using gcc and parse using Sikraken's parser
    ./bin/call_parser.sh $c_files_directory "$base_name".c $gcc_flag
    if [ $? -ne 0 ]; then
        echo "Sikraken regression testing ERROR: Sikraken parsing of $regression_test_file failed"
        exit 1
    else
        echo "Sikraken successfully parsed $regression_test_file"
    fi

    #generate test inputs
    eclipse_call="se_main(['/home/chris/Sikraken/', '"$c_files_directory"/', '"$base_name"', main, debug, testcomp, '$gcc_flag', 2, 2])"
    eclipse -f ./SymbolicExecutor/se_main.pl -e "$eclipse_call"
    if [ $? -ne 0 ]; then
        echo "Sikraken regression testing ERROR: call to ECLiPSe $eclipse_call failed"
    else
        echo "Sikraken generated test inputs for $regression_test_file in $id configuration"
    fi

    #validate test inputs
    testcov_output=$(testcov $testcov_data_model --no-isolation --test-suite "$c_files_directory""/suite-""$base_name"".zip" "$regression_test_file")
    if [ $? -ne 0 ]; then
        echo "Sikraken regression testing ERROR: TestCov test inputs validation of $regression_test_file failed"
    else
        echo "TestCov validated the test inputs for $regression_test_file in $id configuration"    
    fi

done

if [ -f regression_tests_run.log ]; then
    echo -e "\e[31mSikraken regression testing script run_regression.sh has terminated with warnings.\e[0m"
    cat regression_tests_run.log
else
    echo -e "\e[32mSikraken regression testing script run_regression.sh has terminated successfully.\e[0m"
fi