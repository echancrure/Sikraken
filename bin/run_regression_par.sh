#!/bin/bash
#
# Script: run_regression_par.sh
# Author: Chris Meudec
# Date: May 2025 (Updated Oct 2025 for parallel error handling and final summary)
# Description: Runs Sikraken regression tests in parallel, then sequential TestCov validation.
# Usage: ./bin/run_regression_par.sh <number_of_cores> <relative_directory_of_regression_c_files> [-scg] [-d]

clear
echo "PARALLEL Regression Testing"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)" # Script directory
SIKRAKEN_INSTALL_DIR="$SCRIPT_DIR/.."
echo "SIKRAKEN_INSTALL_DIR is $SIKRAKEN_INSTALL_DIR"

script_name=$(basename "$0")

# --- GLOBAL ERROR FLAG ---
PARALLEL_FAIL_FLAG="$SIKRAKEN_INSTALL_DIR/parallel_fail.log"

# --- Usage check ---
if [ $# -lt 2 ] || [ $# -gt 4 ]; then
    echo "Sikraken PARALLEL regression testing ERROR:"
    echo "Usage: $script_name <number_of_cores> <relative_directory_of_regression_c_files> [-scg] [-d]"
    echo "Example: $script_name 8 regression_tests true -d"
    exit 1
fi

# --- Core arguments ---
max_jobs=$1
rel_path_c_file="$2"
c_files_directory="$SIKRAKEN_INSTALL_DIR/$rel_path_c_file"

# --- Defaults ---
shortcutgen=""
debug_mode="release"

# --- Parse optional args ---
shift 2
while [ $# -gt 0 ]; do
    case "$1" in
        -scg)
            shortcutgen=", shortcut_gen"
            ;;
        -d)
            debug_mode="debug"
            ;;
        *)
            echo "Unknown option: $1"
            echo "Usage: $script_name <number_of_cores> <relative_directory_of_regression_c_files> [shortcutgen] [-d]"
            exit 1
            ;;
    esac
    shift
done

# --- Debug info ---
echo "max_jobs     = $max_jobs"
echo "c_files_dir  = $c_files_directory"
echo "shortcutgen  = $shortcutgen"
echo "mode         = $debug_mode"

# Check directory existence
if [ ! -d "$c_files_directory" ]; then
    echo "Sikraken regression testing ERROR: the passed directory of regression files $c_files_directory does not exist."
    exit 1
fi

# Recompile parser
./bin/compile_parser.sh
if [ $? -ne 0 ]; then
    echo "Sikraken regression testing ERROR: Sikraken parser recompilation failed"
    exit 1
else
    echo "Sikraken parser successfully recompiled"
fi

[ -f regression_tests_run.log ] && rm -f regression_tests_run.log
[ -f "$PARALLEL_FAIL_FLAG" ] && rm -f "$PARALLEL_FAIL_FLAG"

# --- Job pool ---
job_pool() {
    while [ "$(jobs -r | wc -l)" -ge "$max_jobs" ]; do
        sleep 1
    done
}

# --- Generate tests in parallel ---
generate_tests() {
    local regression_test_file="$1"
    local base_name=$(basename "$regression_test_file" .c)
    local config_file="$c_files_directory/$base_name.json"
    local yml_file="$c_files_directory/$base_name.yml"

    [ ! -f "$config_file" ] && echo "Sikraken ERROR: Configuration $config_file missing" >> "$PARALLEL_FAIL_FLAG" && return 1

    # Determine data model
    local data_model="ILP32"
    [ -f "$yml_file" ] && data_model=$(grep "data_model:" "$yml_file" | awk '{print $2}')

    local gcc_flag
    case "$data_model" in
        ILP32) gcc_flag="-m32";;
        LP64) gcc_flag="-m64";;
        *) echo "Sikraken ERROR: Unsupported data model $data_model" >> "$PARALLEL_FAIL_FLAG"; return 1;;
    esac

    # Call parser
    call_parser="$SIKRAKEN_INSTALL_DIR/bin/call_parser.sh $rel_path_c_file/$base_name.c $gcc_flag"
    $call_parser
    if [ $? -ne 0 ]; then
        echo "Sikraken ERROR: Parsing $regression_test_file failed" >> "$PARALLEL_FAIL_FLAG"
        return 1
    fi

    # Loop over configurations
    local config_count=$(jq '.configurations | length' "$config_file")
    for i in $(seq 0 $((config_count - 1))); do
        local config=$(jq ".configurations[$i]" "$config_file")
        local algo=$(echo "$config" | jq -r '.algo')

        echo -e "\e[34mGenerating tests for $regression_test_file using algo: $algo\e[0m"
        local log_file="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/sikraken.log"
        local eclipse_call="se_main(['$SIKRAKEN_INSTALL_DIR', '$SIKRAKEN_INSTALL_DIR/$rel_path_c_file', '$base_name', main, $debug_mode, testcomp, '$gcc_flag', $algo $shortcutgen])"
        $SIKRAKEN_INSTALL_DIR/eclipse/bin/x86_64_linux/eclipse -f $SIKRAKEN_INSTALL_DIR/SymbolicExecutor/se_main.pl -e "$eclipse_call" >> $log_file 2>&1
        [ $? -ne 0 ] && echo "Sikraken ERROR: ECLiPSe call failed for $regression_test_file" >> "$PARALLEL_FAIL_FLAG" && return 1

        ###call Testcov with  
        local testcov_dir="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/testcov"
        mkdir -p "$testcov_dir"
        local testcov_log="$testcov_dir/testcov_call.log"
        TMPDIR="$testcov_dir/tmp"
        mkdir -p "$TMPDIR"
        #extract data model in testcov format
        local testcov_data_model
        case "$data_model" in
            ILP32) testcov_data_model="-32";;
            LP64) testcov_data_model="-64";;
        esac
        local testcov_call=(./bin/run_testcov.sh "$regression_test_file" "$testcov_data_model")
        echo -e "\e[34mCalling Testcov for $regression_test_file\e[0m"
        # run it
        "${testcov_call[@]}" >"$testcov_log" 2>&1
        echo -e "\e[32mEnded Testcov for $regression_test_file\e[0m"

    done
}

# ANSI color codes
RED='\033[0;31m'
BOLD='\033[1m'
RED_BG='\033[41m'
WHITE='\033[97m'
NC='\033[0m' # No Color

# Function to check if difference is more than 10%
check_diff() {
    local val1=$1
    local val2=$2
    local show_warning=$3
    
    # Handle empty or non-numeric values
    if [[ -z "$val1" || -z "$val2" ]]; then
        echo "$val1"
        return
    fi
    
    # If expected value is 0, avoid division by zero
    if (( $(echo "$val2 == 0" | bc -l 2>/dev/null || echo "0") )); then
        # If both are 0, no highlighting; if only expected is 0 and actual isn't, highlight
        if (( $(echo "$val1 == 0" | bc -l 2>/dev/null || echo "0") )); then
            echo "$val1"
        else
            if [[ "$show_warning" == "true" ]]; then
                echo -e "${RED_BG}${WHITE}${BOLD}${val1}${NC} ⚠️"
            else
                echo -e "${RED}${BOLD}${val1}${NC}"
            fi
        fi
        return
    fi
    
    # Calculate absolute difference percentage
    local diff=$(echo "scale=2; if ($val2 != 0) (($val1 - $val2) / $val2) * 100 else 0" | bc -l 2>/dev/null)
    
    # Get absolute value
    if (( $(echo "$diff < 0" | bc -l 2>/dev/null) )); then
        local abs_diff=$(echo "$diff * -1" | bc -l)
    else
        local abs_diff=$diff
    fi
    
    # Check if absolute difference is greater than 10%
    if (( $(echo "$abs_diff > 10" | bc -l 2>/dev/null) )); then
        if [[ "$show_warning" == "true" ]]; then
            # With warning icon and background
            echo -e "${RED_BG}${WHITE}${BOLD}${val1}${NC} ⚠️"
        else
            # Just bold red
            echo -e "${RED}${BOLD}${val1}${NC}"
        fi
    else
        echo "$val1"
    fi
}

# --- MAIN EXECUTION ---

# Run Sikraken in parallel
for regression_test_file in "$c_files_directory"/*.c; do
    job_pool
    generate_tests "$regression_test_file" &
done
wait

# Check for parallel errors
if [ -f "$PARALLEL_FAIL_FLAG" ]; then
    echo -e "\n\e[31m--- PARALLEL GENERATION FAILED ---\e[0m"
    cat "$PARALLEL_FAIL_FLAG"
    rm -f "$PARALLEL_FAIL_FLAG"
    exit 1
fi

# --- FINAL SUMMARY WITH EXPECTED VS ACTUAL ---
echo -e "\n================ FINAL SUMMARY ================\n"

for regression_test_file in "$c_files_directory"/*.c; do
    base_name=$(basename "$regression_test_file" .c)
    sikraken_log="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/sikraken.log"
    testcov_log="$SIKRAKEN_INSTALL_DIR/sikraken_output/$base_name/testcov/testcov_call.log"
    config_file="$c_files_directory/$base_name.json"

    # Parse Sikraken log
    if [ -f "$sikraken_log" ]; then
        sik_tests=$(grep "Generated:" "$sikraken_log" | awk '{print $2}' | tail -1)
        sik_edges=$(grep "CFG:" "$sikraken_log" | awk '{print $2}' | tail -1)
        sik_cov=$(grep "Coverage:" "$sikraken_log" | awk '{print $2}' | sed 's/%//' | tail -1)
    else
        sik_tests="NA"; sik_edges="NA"; sik_cov="NA"
    fi

    # Parse TestCov log
    if [ -f "$testcov_log" ]; then
        tc_tests=$(grep "Tests run:" "$testcov_log" | awk '{print $3}' | tail -1)
        tc_goals=$(grep "Number of goals:" "$testcov_log" | awk '{print $4}' | tail -1)
        tc_cov=$(grep "Coverage:" "$testcov_log" | awk '{print $2}' | sed 's/%//' | tail -1)
    else
        tc_tests="NA"; tc_goals="NA"; tc_cov="NA"
    fi

    # Get expected tests and coverage from JSON (first configuration)
    if [ -f "$config_file" ]; then
        expected_tests_number=$(jq -r '.configurations[0].expected_tests_number' "$config_file")
        expected_testcov_coverage=$(jq -r '.configurations[0].expected_testcov_coverage' "$config_file")
        expected_sikraken_edges=$(jq -r '.configurations[0].expected_sikraken_edges' "$config_file")
    else
        expected_tests_number="NA"
        expected_testcov_coverage="NA"
        expected_sikraken_edges="NA"
    fi
    # Check each metric (set third parameter to "true" to show warning icons)
    sik_edges_display=$(check_diff "$sik_edges" "$expected_sikraken_edges" "true")
    sik_tests_display=$(check_diff "$sik_tests" "$expected_tests_number" "true")
    sik_cov_display=$(check_diff "$sik_cov" "$expected_testcov_coverage" "true")

    # Print summary line with highlighting
    echo -e "$base_name.c → Branches: $sik_edges_display sik / $expected_sikraken_edges exp / $tc_goals tcv - Tests: $sik_tests_display sik / $expected_tests_number exp / $tc_tests tcv - Coverage: $sik_cov_display sik / $expected_testcov_coverage exp / $tc_cov tcv"
done
