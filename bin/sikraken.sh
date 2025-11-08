#!/bin/bash
#
# Script: sikraken.sh
# Author: Chris Meudec
# Date: May 2025
# Description: This script is a wrapper for Sikraken symbolic execution tool from C code.
# It preprocesses a C source file using gcc, runs the Sikraken parser, and then calls the symbolic executor.
# It takes four arguments:          
#   1. The debug mode (debug or release)
#   2. The test data generation algorithm (budget or regression)
#   3. The data model (-m32 or -m64)
#   4. The relative path to the C source file (e.g., ./../SampleCode/atry_bitwise.c or .i)
#   Optional: -ss STACK_SIZE in GB
# The script creates the output directory $SIKRAKEN_INSTALL_DIR/sikraken_output/$file_name_no_ext for the generated test inputs and runs the symbolic executor.
# Usage: ./sikraken.sh <debug|release> budget[<Seconds>]|regression[<Restarts>, <Tries>] <-m32|-m64> <relative_dir>/<file_name.c> [-ss STACK_SIZE]
# Example: ./sikraken.sh debug budget[10] -m32 ./../SampleCode/atry_bitwise.c
# Example: ./sikraken.sh release regression[5, 10] -m64 ./../SampleCode/atry_bitwise.c
# Example: ./sikraken.sh -v     (TestComp requirement: output Sikraken version) 
# Dependencies: gcc, eclipse, sikraken_parser.exe

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" #Get the directory of the script <sikraken_install>/bin
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."

VERSION_FILE="$SIKRAKEN_INSTALL_DIR/bin/version.txt"
if [ $1 == "-v" ]; then 
    if [[ -f "$VERSION_FILE" ]]; then
        version=$(head -n 1 "$VERSION_FILE") # Outputs the first line of version.txt
        echo "$version"
        exit 0
    else
        echo "Error: $VERSION_FILE not found."
        exit 1
    fi
fi
version=$(head -n 1 "$VERSION_FILE") # Read the first line of version.txt
echo "$version"

echo "Sikraken from $0 says: SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

# --- Default stack size ---
stack_size_value="$(( 3 * 953 ))M"  # Default 3 GB roughly 3*953 MiB

# --- Parse optional -ss flag at the end ---
if [ "$#" -ge 6 ] && [ "$5" == "-ss" ]; then
    if ! [[ "$6" =~ ^[0-9]+$ ]] || [ "$6" -le 0 ]; then
        echo "Sikraken ERROR from $0: STACK_SIZE for -ss must be a positive integer (GB)."
        exit 1
    fi
    stack_size_value="$(( $6 * 953 ))M"
    set -- "${@:1:4}"  # keep only first 4 positional arguments
fi

# Ensure we have exactly 4 arguments
if [ $# -ne 4 ]; then
    echo "Sikraken from $0 says usage (respect the order): $0 <debug|release> budget[<Seconds>]|regression[<Restarts>, <Tries>] <-m32|-m64> <relative_dir>/<file_name.c>"
    exit 1
fi

debug_mode="$1"
algo="$2"
algo=${algo/\[/\(}  # Replace the first occurrence of [ with (
algo=${algo/\]/\)}  # Replace the first occurrence of ] with )

data_model="$3"                         #e.g. -m32
if [ "$data_model" == "-m32" ]; then
        testcov_data_model="-32"
    elif [ "$data_model" == "-m64" ]; then
        testcov_data_model="-64"
    else
        echo "Sikraken ERROR from $0: Unsupported data model: $data_model"
        exit 1
fi

rel_path_c_file="$4"                    #e.g. ./../SampleCode/atry_bitwise.c or .i

full_path_c_file="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"    #e.g. /home/chris/Sikraken/SampleCode/atry_bitwise.c or .i

file_name_no_ext="${rel_path_c_file%.*}"
file_name_no_ext=$(basename "$file_name_no_ext")

call_parser="$SIKRAKEN_INSTALL_DIR/bin/call_parser.sh $rel_path_c_file $data_model"
echo "Sikraken from $0 says: $call_parser"
$call_parser
# Check if the call_parser was successful
if [ $? -ne 0 ]; then
    echo "Sikraken ERROR from $0: call_parser failed on $call_parser"
    exit 1
fi

echo "Sikraken from $0 Successfully preprocessed $rel_path_c_file and ran sikraken_parser."
if [[ $algo =~ ^budget\([0-9]+\)$ ]]; then
  seconds="${algo//[!0-9]/}"
  echo "Sikraken from $0 says: Please wait $seconds seconds for Sikraken to complete"
else
  echo "Sikraken from $0 says: Please wait for Sikraken to complete its $algo search strategy" 
fi

# Call the symbolic executor via ECLiPSe
eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$output_dir', '$file_name_no_ext', main, '$debug_mode', testcomp, '$data_model', $algo])"
$SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call" -g $stack_size_value -l 1G 

# check if test generation was successful
if [ $? -ne 0 ]; then
    echo "Sikraken ERROR from $0: call to ECLiPSe $eclipse_call failed"
    exit 1
else
    echo "Sikraken from $0 generated test inputs for $file_name_no_ext in $SIKRAKEN_INSTALL_DIR/sikraken_output/$file_name_no_ext/"
    echo "Sikraken from $0 says, now run: ./bin/run_testcov.sh $rel_path_c_file $testcov_data_model"
fi