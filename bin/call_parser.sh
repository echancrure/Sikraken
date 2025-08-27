#!/bin/bash
#
# Script: call_parser.sh
# Author: Chris Meudec
# Date: May 2025
# Description: Calls the Sikraken parser, sikraken_parser.exe, on a C source file.
# This script preprocesses the C source file using gcc (for .c files) and then runs the Sikraken parser on it.
# It takes one compulsory argument and up to 2 optional arguments:
#   1. The relative path to the C source file (e.g., ./../SampleCode/atry_bitwise.c or .i)
#   2. (Optional) The gcc flag for the data model (default is -m32)
#   3. (Optional) The -d flag to enable debug mode
# The target directory for the output is $SIKRAKEN_INSTALL_DIR/sikraken_output/$input_file_no_ext
# Usage: ./call_parser.sh <relative_dir>/<file_name.c> [gcc_flag] [-d]
# Example: ./call_parser.sh ./../SampleCode atry_bitwise.c -m64

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "Sikraken $0 says: SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

# Ensure we have at least 1 argument and a maximum of 3
if [ $# -lt 1 ] || [ $# -gt 3 ]; then
    echo "Sikraken ERROR from $0: usage is $0 <relative_dir>/<file_name.c> [gcc_flag] [-d]"
    exit 1
fi

rel_path_c_file="$1"                    #e.g. ./../SampleCode/atry_bitwise.c or .i
full_path_c_file="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"    #e.g. /home/chris/Sikraken/SampleCode/atry_bitwise.c or .i
input_file_no_ext="${rel_path_c_file%.*}"
input_file_no_ext=$(basename "$input_file_no_ext")
output_directory="$SIKRAKEN_INSTALL_DIR/sikraken_output/$input_file_no_ext"

# Handle optional arguments for data_model and debug mode
if [ "$2" == "-d" ]; then
    debug_mode="-d"
    data_model="-m32" # Default to '-m32' if no data_model is provided
elif [ -n "$2" ]; then
    data_model="$2"
    debug_mode="${3:-""}" # Use $3 for debug mode if provided
else
    data_model="-m32" # Default to '-m32' if $2 is not provided
    debug_mode=""
fi

if [ ! -d "$output_directory" ]; then  # If it doesn't exist, create it
    mkdir -p "$output_directory"
fi

# Check the file extension
file_extension="${rel_path_c_file##*.}"

if [ "$file_extension" == "i" ]; then
    # If the file is already preprocessed (.i), just copy it to $output_directory
    cp "$full_path_c_file" "$output_directory/"
    if [ $? -ne 0 ]; then
        echo "Sikraken ERROR from $0: Failed to copy $full_path_c_file to $output_directory"
        exit 1
    fi
else
    # If the file is not preprocessed, preprocess it with gcc
    gcc_call="gcc -E -P "$full_path_c_file" $data_model -o "$output_directory/$input_file_no_ext.i""
    #echo $gcc_call
    $gcc_call
    # Check if gcc was successful
    if [ $? -ne 0 ]; then
        echo "Sikraken ERROR from $0: gcc failed on $gcc_call"
        exit 1
    fi
fi

# Run the parser
parser_call="./bin/sikraken_parser.exe $debug_mode $data_model -p"$output_directory" "$input_file_no_ext""
$parser_call
# Check if sikraken_parser was successful
if [ $? -ne 0 ]; then
    echo "Sikraken ERROR from $0: sikraken_parser failed on $parser_call"
    exit 1
fi

echo "Sikraken from $0: successfully preprocessed $input_file_no_ext and ran sikraken_parser."