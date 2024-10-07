#!/bin/bash
# Script to create a zip archive with specific files and folder structure

# Define the name of the output zip file
OUTPUT_ZIP="sikraken.zip"

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
)

# Define the list of patterns to exclude (e.g., .git, .vscode, etc.)
EXCLUDE_PATTERNS=(
    "*.git*"
    "*.vscode*"
    "*.project*"
)

# Create the zip archive
zip -r $OUTPUT_ZIP "${FILES_TO_INCLUDE[@]}" -x "${EXCLUDE_PATTERNS[@]}"

echo "Zip archive $OUTPUT_ZIP has been created with the specified files and folders."