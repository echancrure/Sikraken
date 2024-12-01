#!/bin/bash

# Ensure script is passed an argument
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <relative_or_absolute_path_to_timestamp_directory>"
    exit 1
fi

# Convert relative path to absolute path
input_dir=$(realpath "$1")
category=$(basename "$(dirname "$input_dir")")
timestamp=$(basename "$input_dir")
output_file="${input_dir}/category_test_run_results.html"

# Get subdirectory names in $input_dir as benchmarks
benchmarks=$(find "$input_dir" -mindepth 1 -maxdepth 1 -type d -exec basename {} \;)
benchmark_count=$(echo "$benchmarks" | wc -l)
total_coverage=0
rows=""

# Process each benchmark
for benchmark in $benchmarks; do
    benchmark_dir="${input_dir}/${benchmark}"
    plot_file="${benchmark_dir}/sikraken_plot.png"
    log_file="${benchmark_dir}/testcov/testcov_call.log"
    test_run_log="./sikraken_output/${benchmark}/test_run_${benchmark}.log"

    # Ensure benchmark directory exists
    if [ ! -d "$benchmark_dir" ]; then
        echo "Directory for benchmark $benchmark not found, skipping."
        continue
    fi

    # Debug: Verify log file existence
    if [ ! -f "$log_file" ]; then
        echo "Log file not found: $log_file"
        continue
    fi

    # Debug: Output log file content
    #echo "Content of $log_file:"
    #cat "$log_file"

    # Extract information
    test_count=$(grep -oP "Tests in suite:\s+\K\d+" "${log_file}" 2>/dev/null || echo "N/A")
    coverage=$(grep -oP "Coverage:\s+\K[\d.]+(?=%)" "${log_file}" 2>/dev/null || echo "0")
    stack_peak=$(grep -oP "global_stack_peak:\s+\K\d+" "$test_run_log" 2>/dev/null || echo "0")
    stack_peak_mb=$(bc <<< "scale=2; $stack_peak / 1048576")

    # Debug: Show extracted values
    #echo "Benchmark: $benchmark"
    #echo "  Tests in suite: $test_count"
    #echo "  Coverage: $coverage%"
    #echo "  Global stack peak: ${stack_peak_mb} MB"

    # Sum coverage for the total
    total_coverage=$(bc <<< "$total_coverage + $coverage")

    # Highlight rows with 0 tests in light red
    if [ "$test_count" == "0" ] || [ "$test_count" == "N/A" ]; then
        row_class="style='background-color: lightcoral;'"
    else
        row_class=""
    fi

    # Add row to table
    rows+="<tr $row_class>
        <td>${benchmark}</td>
        <td>${test_count}</td>
        <td>${coverage}%</td>
        <td><a href=\"${plot_file}\"><img src=\"${plot_file}\" style=\"max-width: 150px; max-height: 100px;\"></a></td>
        <td>${stack_peak_mb} MB</td>
    </tr>"
done

# Calculate total coverage
total_score=$(bc <<< "scale=2; $total_coverage / 100")


# Generate HTML
cat > "$output_file" << EOF
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>${category} Test Run Results</title>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }
        table, th, td {
            border: 1px solid black;
        }
        th, td {
            padding: 8px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>
    <h1>${category} - ${timestamp}</h1>
    <h2>Number of Benchmarks: ${benchmark_count}</h2>
    <h2>Overall Score Achieved: ${total_score}</h2>
    <table>
        <thead>
            <tr>
                <th>Benchmark</th>
                <th>Number of Tests</th>
                <th>Coverage Achieved</th>
                <th>Graph</th>
                <th>Peak Global Stack (MB)</th>
            </tr>
        </thead>
        <tbody>
            ${rows}
        </tbody>
    </table>
</body>
</html>
EOF

echo "HTML report generated: $output_file"
