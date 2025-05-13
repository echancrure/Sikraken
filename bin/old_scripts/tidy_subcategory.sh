#!/bin/bash
# DEPRECATED?
# Script: tidy_subcategory.sh
# Author: Chris Meudec
# Date: May 2025
# Description: This script deletes .c files if their corresponding .yml file does not contain a specific string.
# It is used to clean up the directory by removing unnecessary files.
# Usage: ./tidy_subcategory.sh <directory>
# Example: ./tidy_subcategory.sh /home/chris/sv-benchmarks/c/ECA/2024_Dec_01_07_04AM

# Directory to search for files
DIRECTORY=${1:-.}  # Use the first argument as directory or default to current directory

# The string to search for
SEARCH_STRING="property_file: ../properties/coverage-branches.prp"

# Iterate through all *.c files in the directory
find "$DIRECTORY" -type f -name "*.c" | while read -r c_file; do
  # Get the corresponding .yml file
  yml_file="${c_file%.c}.yml"

  # Check if the .yml file exists and contains the search string
  if [[ ! -f "$yml_file" ]] || ! grep -qF "$SEARCH_STRING" "$yml_file"; then
    # If the .yml file doesn't exist or the string is not found, delete the .c file
    echo "Deleting $c_file as $yml_file does not contain the required string."
    rm "$c_file"
  fi
done
