#!/bin/bash
#
# Script: generate_chris_set.sh
# Author: Chris Meudec
# Date: May 2025
# Description: This script generates a file named chris.set containing paths to .yml files that match a specific pattern.
# It searches for .yml files in the specified root folder and its subfolders, filtering for files that contain a specific line.
# It then randomly selects two matching files from each subfolder and writes their relative paths to chris.set.
# The script also remove duplicates and sorts the output file.
# Usage: ./generate_chris_set.sh
# Example: ./generate_chris_set.sh


# Define the root folder and output file
ROOT_FOLDER="/home/chris/sv-benchmarks/c"
OUTPUT_FILE="chris.set"

# Clear the output file
> "$OUTPUT_FILE"

# Loop through each subfolder containing .yml files
find "$ROOT_FOLDER" -type d | while read -r subfolder; do
    # Collect all .yml files in the subfolder
    yml_files=($(find "$subfolder" -maxdepth 1 -type f -name "*.yml"))

    # Filter for files containing the required line
    matching_files=()
    for file in "${yml_files[@]}"; do
        if grep -q "  - property_file: ../properties/coverage-branches.prp" "$file"; then
            matching_files+=("$file")
            echo "Added matching file $file"
        fi
    done

    # If there are at least two matching files, pick two at random
    if [ "${#matching_files[@]}" -ge 2 ]; then
        random_files=($(shuf -e "${matching_files[@]}" -n 2))
        # Write the relative paths to the output file
        for file in "${random_files[@]}"; do
            relative_path=$(realpath --relative-to="$ROOT_FOLDER" "$file")
            echo "$relative_path" >> "$OUTPUT_FILE"
        done
    fi
done

# Deduplicate and sort the output file
sort -u -o "$OUTPUT_FILE" "$OUTPUT_FILE"

echo "chris.set has been generated with random .yml file paths."