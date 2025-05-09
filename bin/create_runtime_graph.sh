#!/bin/bash
#
# Script: create_runtime_graph.sh
# Author: Chris Meudec
# Date: May 2025
# Description: This script generates a runtime graph from a Sikraken log file for a single test run.
# It extracts the "Test generated" and "Restart single test budget changed" times from the log file 
# It creates a PNG file using GNUPLOT, named after the input file, in the same directory as the sikraken.log.
# Usage: ./create_runtime_graph.sh <input_log_file>
# Example: ./create_runtime_graph.sh /path/to/sikraken.log

# Ensure script is passed an argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <input_log_file>"
    exit 1
fi

INPUT_FILE="$1"
INPUT_FILENAME=$(basename "$INPUT_FILE" .log)  # Extract the base name (without .log extension)
INPUT_DIR=$(dirname "$1") 
BENCHMARK=$(basename "$INPUT_DIR")

OUTPUT_FILE="$INPUT_DIR/${INPUT_FILENAME}_plot.png"  # Use the input file name as part of the output file name

# Temporary file to store the extracted data for plotting
TMP_FILE_TEST="$INPUT_DIR/${INPUT_FILENAME}_test_generated.csv"
TMP_FILE_BUDGET="$INPUT_DIR/${INPUT_FILENAME}_budget_changed.csv"

# Clear any previous content in the temporary files
> "$TMP_FILE_TEST"
> "$TMP_FILE_BUDGET"

# Extract Test Generated Times and Overall Elapsed Times into separate files
grep "Dev Info: Test generated" "$INPUT_FILE" | awk -F"Test generated in | seconds; overall elapsed time is " '{print $2 "," $3}' | sed 's/ seconds//' >> "$TMP_FILE_TEST"

# Extract Restart Budget Changed Times and Overall Elapsed Times into separate files
grep "Dev Info: Restart single test budget changed" "$INPUT_FILE" | awk -F"Restart single test budget changed to: | seconds; overall elapsed time is " '{print $2 "," $3}' | sed 's/ seconds//' >> "$TMP_FILE_BUDGET"

# Create a GNUPLOT script
GNUPLOT_SCRIPT=$(mktemp "plot_times-XXXXXX.gp")
echo "Generated file: $GNUPLOT_SCRIPT"

#set term eps
cat << EOF > $GNUPLOT_SCRIPT
set terminal pngcairo size 800,600
set output '$OUTPUT_FILE'
set title "$BENCHMARK: Sikraken Test Run"
set datafile separator ","
set xlabel "Overall Elapsed Time (seconds)"
set ylabel "Time (seconds)"
set grid

# Plot the two datasets separately as two curves using column 2 (overall elapsed times) as x-axis
plot "$TMP_FILE_TEST" using 2:1 with linespoints title "Test Generated Times", \
     "$TMP_FILE_BUDGET" using 2:1 with linespoints title "Budget Changed Times"
EOF

# Generate the graph
gnuplot $GNUPLOT_SCRIPT

# Clean up temporary files
#rm "$TMP_FILE_TEST" "$TMP_FILE_BUDGET"
rm -f $GNUPLOT_SCRIPT

echo "Sikraken $0 log: Graph saved as '$OUTPUT_FILE'."