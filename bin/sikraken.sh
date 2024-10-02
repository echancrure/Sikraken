#!/bin/bash

# top-level command 

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
echo "Script dir is $SCRIPT_DIR"
# we assume the following arguments: <-m32|-m64>  <relative_dir>/<file_name.c>
# <relative_dir> is relative to the working directory

# Ensure we have at least 2 arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <-m32|-m64>  <relative_dir>/<file_name.c>"
    exit 1
fi

data_model="$1"                         #e.g. -m32
rel_path_c_file="$2"                    #e.g. ./../SampleCode/atry_bitwise.c
full_path_c_file="$SCRIPT_DIR/$rel_path_c_file"    #e.g. /home/chris/Sikraken/SampleCode/atry_bitwise.c

file_name_no_ext=$(basename "$rel_path_c_file" .c)
directory=$(dirname "$(realpath "$full_path_c_file")")
mkdir -p $SCRIPT_DIR/../sikraken_output/$file_name_no_ext
# Preprocess the file using gcc
gcc -E -P "$full_path_c_file" $data_model -o "$SCRIPT_DIR/../sikraken_output/$file_name_no_ext/$file_name_no_ext.i"

# Check if gcc was successful
if [ $? -ne 0 ]; then
    echo "Error: gcc failed on gcc -E -P "$full_path_c_file" $data_model -o "$SCRIPT_DIR/../sikraken_output/$file_name_no_ext/$file_name_no_ext.i""
    exit 1
fi


# Run the parser
$SCRIPT_DIR/sikraken_parser.exe $data_model -p$SCRIPT_DIR/../sikraken_output/$file_name_no_ext/ $file_name_no_ext

# Check if sikraken_parser was successful
if [ $? -ne 0 ]; then
    echo "Error: sikraken_parser failed on $SCRIPT_DIR/sikraken_parser.exe $data_model -p$SCRIPT_DIR/../sikraken_output/$file_name_no_ext/ $file_name_no_ext"
    exit 1
fi

echo "Successfully preprocessed $rel_path_c_file and ran sikraken_parser."

# Call the symbolic executor via ECLiPSe