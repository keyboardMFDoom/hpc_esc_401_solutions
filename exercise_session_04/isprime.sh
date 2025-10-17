#!/bin/bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <positive integer>"
    exit 1
fi

num="$1"

if ! [[ "$num" =~ ^-?[0-9]+$ ]]; then
    echo "ERROR: The given input is not a number: $num"
    exit 2
fi

if [ "$num" -le 1 ]; then
    echo "ERROR: The given input is not a positive integer: $num"
    exit 3
fi

if [[ "$num" =~ \. ]]; then
    echo "ERROR: The given input is not a positive integer: $num"
    exit 4
fi

count=$(factor "$num" | wc -w)

if [ "$count" -eq 2 ]; then
    echo "$num is prime"
else
    echo "$num is composite"
fi

