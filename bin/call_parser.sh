#!/bin/bash

# Ensure we have at least 2 arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <directory> <file_no_ext> [gcc_flag]"
    exit 1
fi

input_file_no_ext="$2"
output_file="$input_file_no_ext.i"
directory="$1"

# Optional third argument for data_model, default to '-m32' if absent
gcc_flag="${3:--m32}"

# Preprocess the file using gcc
gcc -E -P "$directory/$input_file_no_ext.c" $gcc_flag -o "$directory/$output_file"

# Check if gcc was successful
if [ $? -ne 0 ]; then
    echo "Error: gcc failed on gcc -E -P "$directory/$input_file_no_ext.c" $gcc_flag -o "$directory/$output_file""
    exit 1
fi

# Run the parser
./bin/sikraken_parser.exe -d $gcc_flag -p"$directory" "$input_file_no_ext"

# Check if sikraken_parser was successful
if [ $? -ne 0 ]; then
    echo "Error: sikraken_parser failed on ./bin/sikraken_parser.exe -d $gcc_flag -p"$directory" "$input_file_no_ext""
    exit 1
fi

echo "Successfully preprocessed $input_file_no_ext and ran sikraken_parser."