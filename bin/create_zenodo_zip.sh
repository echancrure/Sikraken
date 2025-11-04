#!/bin/bash
#
# Script: create_zenodo_zip.sh
# Author: Chris Meudec
# Date: May 2025
# Description: Creates sikraken.zip for Zenodo submission with all files under a common root.

set -e  # Exit on error

# Remove old zip if exists
rm -f ./sikraken.zip

# Define root for zip
OUTPUT_ZIP="sikraken.zip"
TEMP_ROOT="sikraken"

# Remove old temp folder if exists
rm -rf "$TEMP_ROOT"
mkdir -p "$TEMP_ROOT"

# List of files and folders to include (relative paths)
FILES_TO_INCLUDE=(
    "bin"
    "Documentation"
    "eclipse"
    "PTC-Solver"
    "SampleCode/simple_if.c"
    "SymbolicExecutor"
    "LICENSE"
    "README.md"
    "smoketest.sh"
)

# Patterns to exclude in zip
EXCLUDE_PATTERNS=(
    "*.git*"
    "*.vscode*"
    "*.project*"
)

# Copy files preserving directory structure
for FILE in "${FILES_TO_INCLUDE[@]}"; do
    cp --parents -r "$FILE" "$TEMP_ROOT/"
done

# Create zip from temp root
zip -r "$OUTPUT_ZIP" "$TEMP_ROOT" -x "${EXCLUDE_PATTERNS[@]}"

# Clean up
rm -rf "$TEMP_ROOT"

echo "Zip archive $OUTPUT_ZIP created with all files under $TEMP_ROOT."
