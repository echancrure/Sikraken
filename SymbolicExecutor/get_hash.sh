#!/usr/bin/env bash
set -euo pipefail

file_path="$1"

if [[ -f "$file_path" ]]; then
    # Print *only* the hash to stdout; nothing else
    sha256sum -- "$file_path" | awk '{print $1}'
else
    echo "get_hash.sh: file not found: $file_path" >&2
    exit 2
