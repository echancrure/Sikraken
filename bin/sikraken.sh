#!/bin/bash

# top-level command for testcomp: parses and generate test inputs for one file file foo.c

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "Sikraken wrapper sikraken.sh says: SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

# we assume the following arguments: <-m32|-m64>  <relative_dir>/<file_name.c>
# <relative_dir> is relative to <SIKRAKEN_INSTALL_DIR>

# Ensure we have exactly 4 arguments
if [ $# -ne 4 ]; then
    echo "Sikraken wrapper sikraken.sh says usage: $0 <-m32|-m64>  <debug|release> <relative_dir>/<file_name.c> \"budget(<Seconds>)|regression(<Restarts>, <Tries>)\""
    exit 1
fi

data_model="$1"                         #e.g. -m32
if [ "$data_model" == "-m32" ]; then
        testcov_data_model="-32"
    elif [ "$data_model" == "-m64" ]; then
        testcov_data_model="-64"
    else
        echo "Sikraken wrapper ERROR: Unsupported data model: $data_model"
        exit 1
fi
debug_mode="$2"
rel_path_c_file="$3"                    #e.g. ./../SampleCode/atry_bitwise.c
algo="$4"
full_path_c_file="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"    #e.g. /home/chris/Sikraken/SampleCode/atry_bitwise.c

file_name_no_ext=$(basename "$rel_path_c_file" .c)

output_dir="$SIKRAKEN_INSTALL_DIR/sikraken_output/$file_name_no_ext"

mkdir -p $output_dir

# Preprocess the file using gcc
gcc -E -P "$full_path_c_file" $data_model -o "$output_dir/$file_name_no_ext.i"

# Check if gcc was successful
if [ $? -ne 0 ]; then
    echo "Sikraken wrapper Error: gcc failed on gcc -E -P "$full_path_c_file" $data_model -o "$output_dir/$file_name_no_ext.i""
    exit 1
fi


# Run the parser
$SIKRAKEN_INSTALL_DIR/bin//sikraken_parser.exe $data_model -p$output_dir $file_name_no_ext

# Check if sikraken_parser was successful
if [ $? -ne 0 ]; then
    echo "Sikraken wrapper Error: sikraken_parser failed on $SIKRAKEN_INSTALL_DIR/bin//sikraken_parser.exe $data_model -p$output_dir $file_name_no_ext"
    exit 1
fi

echo "Sikraken wrapper Successfully preprocessed $rel_path_c_file and ran sikraken_parser."
if [[ $algo =~ ^budget\([0-9]+\)$ ]]; then
  seconds="${algo//[!0-9]/}"
  echo "Sikraken wrapper says: Please wait $seconds seconds for Sikraken to complete"
else
  echo "Sikraken wrapper says: Please wait for Sikraken to complete its $algo search strategy" 
fi

# Call the symbolic executor via ECLiPSe
eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$output_dir', '$file_name_no_ext', main, '$debug_mode', testcomp, '$data_model', $algo])"
$SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call"

# check if test generation was successful
if [ $? -ne 0 ]; then
    echo "Sikraken wrapper ERROR: call to ECLiPSe $eclipse_call failed"
    exit 1
else
    echo "Sikraken wrapper generated test inputs for $file_name_no_ext in $SIKRAKEN_INSTALL_DIR/sikraken_output/$file_name_no_ext/"
    echo "Sikraken wrapper says: run the tests with: testcov --no-isolation $testcov_data_model --test-suite ./sikraken_output/$file_name_no_ext/test-suite.zip $3"
fi