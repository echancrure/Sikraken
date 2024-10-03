#!/bin/bash

# top-level command for testcomp: parses and generate test inputs for one file file foo.c

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "Sikraken testcomp wrapper sikraken.sh says: SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

# we assume the following arguments: <-m32|-m64>  <relative_dir>/<file_name.c>
# <relative_dir> is relative to <SIKRAKEN_INSTALL_DIR>

# Ensure we have at least 2 arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <-m32|-m64>  <relative_dir>/<file_name.c>"
    exit 1
fi

data_model="$1"                         #e.g. -m32
rel_path_c_file="$2"                    #e.g. ./../SampleCode/atry_bitwise.c
full_path_c_file="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"    #e.g. /home/chris/Sikraken/SampleCode/atry_bitwise.c

file_name_no_ext=$(basename "$rel_path_c_file" .c)

output_dir="$SIKRAKEN_INSTALL_DIR/sikraken_output/$file_name_no_ext"

mkdir -p $output_dir

# Preprocess the file using gcc
gcc -E -P "$full_path_c_file" $data_model -o "$output_dir/$file_name_no_ext.i"

# Check if gcc was successful
if [ $? -ne 0 ]; then
    echo "Error: gcc failed on gcc -E -P "$full_path_c_file" $data_model -o "$output_dir/$file_name_no_ext.i""
    exit 1
fi


# Run the parser
$SIKRAKEN_INSTALL_DIR/bin//sikraken_parser.exe $data_model -p$output_dir $file_name_no_ext

# Check if sikraken_parser was successful
if [ $? -ne 0 ]; then
    echo "Error: sikraken_parser failed on $SIKRAKEN_INSTALL_DIR/bin//sikraken_parser.exe $data_model -p$output_dir $file_name_no_ext"
    exit 1
fi

echo "Successfully preprocessed $rel_path_c_file and ran sikraken_parser."

# Call the symbolic executor via ECLiPSe
eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$output_dir', '$file_name_no_ext', main, release, testcomp, '$data_model', budget(30)])"
$SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call"

# check if test generation was successful
if [ $? -ne 0 ]; then
    echo "Sikraken regression testing ERROR: call to ECLiPSe $eclipse_call failed"
    exit 1
else
    echo "Sikraken generated test inputs for $file_name_no_ext"
fi