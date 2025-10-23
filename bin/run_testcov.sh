#!/bin/bash

# --- VALIDATE INPUT ---
if [ $# -ne 2 ]; then
    echo "Usage: $0 <relative_path_to_c_file> <testcov_data_model>"
    exit 1
fi
rel_path_c_file="$1"      # e.g. ./../SampleCode/atry_bitwise.c or .i
testcov_data_model="$2"

# --- ALWAYS RESOLVE BASE DIR (script is in bin/) ---
BASE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# if user gave absolute path → keep it as-is, otherwise prepend BASE_DIR
if [[ "$rel_path_c_file" = /* ]]; then
    full_c_file="$(realpath -m "$rel_path_c_file")"
else
    full_c_file="$(realpath -m "$BASE_DIR/$rel_path_c_file")"
fi

file_name_no_ext="${full_c_file%.*}"
base_name=$(basename "$file_name_no_ext")

# --- Always write to absolute output paths ---
result_dir="$BASE_DIR/sikraken_output/$base_name"

# clean run: delete previous testcov directory for that C file and re-create it 
rm -rf "$result_dir/testcov"
mkdir -p "$result_dir/testcov"

zipfile="$result_dir/test-suite.zip"
rm -f "$zipfile"
zip -r "$zipfile" "$result_dir/test-suite"

#Oct 25 calling testcov in new fast mode 
testcov_call="testcov --fast $testcov_data_model --test-suite \"$zipfile\" \"$full_c_file\" --output \"$result_dir/testcov\" "

echo "CALLING TESTCOV: $testcov_call"
eval $testcov_call

[ $? -ne 0 ] && echo "ERROR: TestCov validation failed for $rel_path_c_file" && exit 1
