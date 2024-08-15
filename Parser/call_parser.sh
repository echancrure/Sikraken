#!/bin/bash

# Ensure we have 2 arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <directory> <file>"
    exit 1
fi

input_file="$2"
output_file="${input_file%.*}.i"
directory="$1"

# Preprocess the file using gcc
gcc -E -P "$directory/$input_file" -o "$directory/$output_file"

# Check if gcc was successful
if [ $? -ne 0 ]; then
    echo "Error: gcc failed to preprocess $input_file"
    exit 1
fi

# Run the parser
./bin/sikraken_parser.exe -d -p"$directory" "$input_file"

# Check if sikraken_parser was successful
if [ $? -ne 0 ]; then
    echo "Error: sikraken_parser failed on $input_file"
    exit 1
fi

echo "Successfully preprocessed $input_file and ran sikraken_parser."
