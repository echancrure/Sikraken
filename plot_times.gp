set terminal pngcairo size 800,600
set output './SikrakenDevSpace/categories/Termination-MainControlFlow/2024_Dec_01_07_04AM/sqrt2-both-nt/sikraken_plot.png'
set title "./SikrakenDevSpace/categories/Termination-MainControlFlow/2024_Dec_01_07_04AM/sqrt2-both-nt/sikraken_plot.png: Sikraken Test Run"
set datafile separator ","
set xlabel "Overall Elapsed Time (seconds)"
set ylabel "Time (seconds)"
set grid

# Plot the two datasets separately as two curves using column 2 (overall elapsed times) as x-axis
plot "./SikrakenDevSpace/categories/Termination-MainControlFlow/2024_Dec_01_07_04AM/sqrt2-both-nt/sikraken_test_generated.csv" using 2:1 with linespoints title "Test Generated Times",      "./SikrakenDevSpace/categories/Termination-MainControlFlow/2024_Dec_01_07_04AM/sqrt2-both-nt/sikraken_budget_changed.csv" using 2:1 with linespoints title "Budget Changed Times"
