#!/bin/bash
# DEPRECATED?
# Script: sum_coverages.sh
# Author: Chris Meudec
# Date: May 2025
# Description: This script calculates the total raw score from a file containing percentage values.
# Usage: ./sum_coverages.sh <file>
# Example: ./sum_coverages.sh coverage.txt


# Check if the file argument is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <file>"
  exit 1
fi

# File containing the percentage values
file="$1"

# Extract the percentage values, remove the '%' symbol, and sum them
total=$(grep -oP 'Coverage: \K[\d.]+(?=%)' "$file" | awk '{sum += $1} END {print sum / 100}')

echo "Total raw score: $total"