set terminal pngcairo size 800,600
set output './SikrakenDevSpace/categories/chris/2024_Dec_05_11_54PM/Dubois-021/sikraken_plot.png'
set title "./SikrakenDevSpace/categories/chris/2024_Dec_05_11_54PM/Dubois-021/sikraken_plot.png: Sikraken Test Run"
set datafile separator ","
set xlabel "Overall Elapsed Time (seconds)"
set ylabel "Time (seconds)"
set grid

# Plot the two datasets separately as two curves using column 2 (overall elapsed times) as x-axis
plot "./SikrakenDevSpace/categories/chris/2024_Dec_05_11_54PM/Dubois-021/sikraken_test_generated.csv" using 2:1 with linespoints title "Test Generated Times",      "./SikrakenDevSpace/categories/chris/2024_Dec_05_11_54PM/Dubois-021/sikraken_budget_changed.csv" using 2:1 with linespoints title "Budget Changed Times"
