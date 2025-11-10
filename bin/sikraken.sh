#!/bin/bash
#
# Script: sikraken.sh
# Author: Chris Meudec
# Date: Nov 2025
# Description: Wrapper for Sikraken symbolic execution tool from C code.
# Usage: ./sikraken.sh [debug|release] [budget[seconds]|regression[restarts,tries]] [-m32|-m64] [-ss STACK_SIZE] <relative_dir>/<file_name.c>
# Defaults: mode=debug, data_model=-m32, stack_size=3 (i.e. 3GB ~2859MiB)
# Example: ./sikraken.sh debug budget[1] -ss 1 SampleCode/simple_if.c

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
VERSION_FILE="$SIKRAKEN_INSTALL_DIR/bin/version.txt"

# --- Version check ---
if [ "$1" == "-v" ]; then
    if [[ -f "$VERSION_FILE" ]]; then
        head -n 1 "$VERSION_FILE"
        exit 0
    else
        echo "Error: $VERSION_FILE not found."
        exit 1
    fi
fi

version=$(head -n 1 "$VERSION_FILE" 2>/dev/null)
echo "$version"
echo "Sikraken from $0 says: SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

# --- Defaults ---
debug_mode="debug"
data_model="-m32"
stack_size_value="$((3 * 953))M"
algo=""
rel_path_c_file=""

# --- Parse all arguments except last ---
while [[ $# -gt 1 ]]; do
    case "$1" in
        debug|release)
            debug_mode="$1"
            ;;
        budget*|regression*)
            algo="${1//[/\(}"
            algo="${algo//]/\)}"
            ;;
        -m32|-m64)
            data_model="$1"
            ;;
        -ss)
            shift
            if [[ -z "$1" || ! "$1" =~ ^[0-9]+$ || "$1" -le 0 ]]; then
                echo "Sikraken ERROR: STACK_SIZE for -ss must be a positive integer (GB)."
                exit 1
            fi
            stack_size_value="$(( $1 * 953 ))M"
            ;;
        *)
            echo "Sikraken ERROR: Unknown argument: $1"
            exit 1
            ;;
    esac
    shift
done

# --- Last argument must be C source path ---
rel_path_c_file="$1"
if [[ ! -f "$rel_path_c_file" ]]; then
    echo "Sikraken ERROR: C source file '$rel_path_c_file' not found."
    exit 1
fi

# --- Validate data model ---
case "$data_model" in
    -m32) testcov_data_model="-32" ;;
    -m64) testcov_data_model="-64" ;;
    *) echo "Sikraken ERROR: Unsupported data model: $data_model"; exit 1 ;;
esac

echo "Mode: $debug_mode"
echo "Algorithm: $algo"
echo "Data model: $data_model"
echo "Stack size: $stack_size_value"
echo "C file: $rel_path_c_file"         

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