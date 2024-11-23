#!/bin/bash

# Input file
INPUT_FILE="$1"
INPUT_FILENAME=$(basename "$INPUT_FILE" .log)  # Extract the base name (without .log extension)
INPUT_DIR=$(dirname "$1") 
OUTPUT_FILE="$INPUT_DIR/${INPUT_FILENAME}_plot.png"  # Use the input file name as part of the output file name

TEMP_FILE1="generated_times.dat"
TEMP_FILE2="single_test_times.dat"

# Cleanup temp files if they exist
rm -f $TEMP_FILE1 $TEMP_FILE2

# Extract values with their line number for "Test generated"
grep -n -oP 'Dev Info: Test generated in \K[0-9.]+(?= seconds)' "$INPUT_FILE" | \
    awk -F: '{print $1, $2}' > "$TEMP_FILE1"

# Extract values with their line number for "Using for a single test"
grep -n -oP 'Single test budget changed to: \K[0-9.]+(?= seconds)' "$INPUT_FILE" | \
    awk -F: '{print $1, $2}' > "$TEMP_FILE2"

# Check if any data was extracted
if [[ ! -s $TEMP_FILE1 && ! -s $TEMP_FILE2 ]]; then
    echo "No matching data found for either type."
    exit 1
fi

# Create a GNUPLOT script
GNUPLOT_SCRIPT="plot_times.gp"

cat << EOF > $GNUPLOT_SCRIPT
set terminal pngcairo size 800,600
set output '$OUTPUT_FILE'
set title "Evolution of Times"
set xlabel "Line Number"
set ylabel "Time (seconds)"
set grid
plot \
    "$TEMP_FILE1" using 1:2 with linespoints title "Test generated", \
    "$TEMP_FILE2" using 1:2 with linespoints title "Budget"
EOF

# Generate the graph
gnuplot $GNUPLOT_SCRIPT

# Cleanup temporary files
rm -f $TEMP_FILE1 $TEMP_FILE2 $GNUPLOT_SCRIPT

echo "Graph saved as '$OUTPUT_FILE'."
