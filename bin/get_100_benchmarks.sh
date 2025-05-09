#!/bin/bash
#
# Script: get_100_benchmarks.sh
# Author: Chris Meudec
# Date: May 2025
# Description: One time script, not portable due to hardcoded paths, it selects 100 random .c files from the source directory and copies them to the output directory.
# It uses the directories specified in categories.txt to determine which files to include.
# The script uses the find command to locate .c files in the specified directories and then shuffles the list to select 100 random files.
# It also creates the output directory if it doesn't exist.
# Usage: ./get_100_benchmarks.sh
# Example: ./get_100_benchmarks.sh

# Set the source directory
SOURCE_DIR="/home/chris/sv-benchmarks/c"

# Set the output directory where the selected files will be copied
OUTPUT_DIR="/home/chris/Sikraken/SikrakenDevSpace/benchmark_subset"

# Number of files to pick
NUM_FILES=100

# Path to categories.txt (containing directories to include)
CATEGORIES_FILE="/home/chris/Sikraken/SikrakenDevSpace/categories.txt"

# Read the directories to include from categories.txt
INCLUDE_DIRS=$(cat "$CATEGORIES_FILE")

# Build the find command with inclusions
FILES=""
for DIR in $INCLUDE_DIRS; do
  FILES="$FILES $(find "$SOURCE_DIR/$DIR" -type f -name "*.c")"
done

# Shuffle the list of files and pick the first 100
SELECTED_FILES=$(echo "$FILES" | shuf | head -n $NUM_FILES)

# Create the output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Copy the selected files to the output directory
for FILE in $SELECTED_FILES; do
  cp "$FILE" "$OUTPUT_DIR"
done

echo "Copied $NUM_FILES .c files to $OUTPUT_DIR"
