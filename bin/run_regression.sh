#!/bin/bash

clear

# parse regression test
# generate test for example
# run test driver (e.g. testcov for testcomp regressin test)
# repeat for all regression tests


# re-compile the parser
./bin/compile_parser.sh
if [ $? -ne 0 ]; then
    echo "run_regression.sh Error: Sikraken parser recompilation failed"
    exit 1
else
    echo "run_regression.sh Success: Sikraken parser successfully recompiled"
fi

regression_test_file="testcov_simple_if.c"

#parse the regression test
./bin/call_parser.sh './SampleCode' $regression_test_file
if [ $? -ne 0 ]; then
    echo "run_regression.sh Error: Sikraken parsing of $regression_test_file failed"
    exit 1
else
    echo "run_regression.sh Success: Sikraken successfully parsed $regression_test_file"
fi

#generate test inputs
eclipse -f ./SymbolicExecutor/se_main.pl -e "se_main('/home/chris/Sikraken/', '/home/chris/Sikraken/SampleCode/', ${regression_test_file%.*}, main, debug, testcomp)"
if [ $? -ne 0 ]; then
    echo "run_regression.sh Error: Sikraken test inputs generation of $regression_test_file failed"
    exit 1
else
    echo "run_regression.sh Success: Sikraken successfully generated test inputs for $regression_test_file"    
fi

#validate test inputs
testcov --no-isolation --test-suite "./SampleCode/suite-${regression_test_file%.*}.zip" "./SampleCode/$regression_test_file"
if [ $? -ne 0 ]; then
    echo "run_regression.sh Error: Sikraken test inputs validation of $regression_test_file failed"
    exit 1
else
    echo "run_regression.sh Success: Sikraken successfully validated test inputs for $regression_test_file"    
fi