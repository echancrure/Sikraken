#!/bin/bash

rel_path_c_file="$1"                    #e.g. ./../SampleCode/atry_bitwise.c
testcov_data_model="$2"

file_name_no_ext=$(basename "$rel_path_c_file" .c)

rm -f test-suite.zip
zip -r test-suite ./sikraken_output/$file_name_no_ext/test-suite
testcov --no-isolation $testcov_data_model --test-suite test-suite.zip $rel_path_c_file 