#!/bin/bash

# parse regression test
# generate test for example
# run test driver (e.g. testcov for testcomp regressin test)
# repeat for all regerssion tests

# re-compile the parser
./../compile_parser.sh

# Check if recompilation was successful
if [ $? -ne 0 ]; then
    echo "Error: Sikraken parser recompilation failed"
    exit 1
fi

#parse the regression test
./../call_parser.sh '.' testcov_simple_if.c
if [ $? -ne 0 ]; then
    echo "Error: Sikraken parsing failed"
    exit 1
fi
