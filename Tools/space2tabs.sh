#!/bin/bash

unexpand_func () {
    echo "File: $1"
    unexpand -t 4 --first-only "$1" > "$1.tmp"
    mv "$1.tmp" "$1"
}

export -f unexpand_func

find . -type d \( -path ./src/ASF \) -prune -o -name "*.[ch]" -exec bash -c 'unexpand_func {}' \;
