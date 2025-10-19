#!/bin/bash
#
# Script: create_zenodo_zip.sh
# Author: Chris Meudec
# Date: May 2025
# Description: This script creates a zip archive, sikraken.zip, with specific files and folder structure of the Sikraken project for Zenodo.
# It is used for TestComp submission to Zenodo.
# It includes specific files and folders while excluding certain patterns.
# Usage: ./create_zenodo_zip.sh
# Dependencies: zip

# Define the name of the output zip file
OUTPUT_ZIP="sikraken.zip"

# Create a temporary root directory
TEMP_ROOT="sikraken"
mkdir -p "$TEMP_ROOT"

# Define the list of files and folders you want to include in the zip
FILES_TO_INCLUDE=(
    "./bin"
    "./Documentation"
    "./eclipse"
    "./PTC-Solver"
    "./SampleCode/simple_if.c"
    "./SymbolicExecutor"
    "./LICENSE"
    "./README.md"
    "./smoketest.sh"
)

# Define the list of patterns to exclude (e.g., .git, .vscode, etc.)
EXCLUDE_PATTERNS=(
    "*.git*"
    "*.vscode*"
    "*.project*"
)

# Copy files to the temporary root directory
for FILE in "${FILES_TO_INCLUDE[@]}"; do
    cp -r "$FILE" "$TEMP_ROOT/"
done

# Create the zip archive from the temporary root directory
zip -r "$OUTPUT_ZIP" "$TEMP_ROOT" -x "${EXCLUDE_PATTERNS[@]}"

# Clean up by removing the temporary root directory
rm -rf "$TEMP_ROOT"

echo "Zip archive $OUTPUT_ZIP has been created with the specified files and folders."