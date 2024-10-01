#!/bin/bash

# top-level command 
# working directory is /sikraken/bin
# we assume the following arguments: <-m32|-m64>  <relative_dir>/<file_name.c>
# <relative_dir> is relative to the working directory

# Ensure we have at least 2 arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <-m32|-m64>  <relative_dir>/<file_name.c>"
    exit 1
fi

data_model="$1"                         #e.g. -m32
rel_path_c_file="$2"                    #e.g. ./../SampleCode/atry_bitwise.c

output_file="${rel_path_c_file%.c}.i"   #remove .c and add .i

# Preprocess the file using gcc
gcc -E -P "$rel_path_c_file" $data_model -o $output_file

# Check if gcc was successful
if [ $? -ne 0 ]; then
    echo "Error: gcc failed to preprocess $rel_path_c_file"
    exit 1
fi

# Run the parser
./bin/sikraken_parser.exe $data_model $rel_path_c_file

# Check if sikraken_parser was successful
if [ $? -ne 0 ]; then
    echo "Error: sikraken_parser failed on $rel_path_c_file"
    exit 1
fi

echo "Successfully preprocessed $rel_path_c_file and ran sikraken_parser."