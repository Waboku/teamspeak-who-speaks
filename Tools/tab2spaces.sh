#!/bin/bash

expand_func () {
    echo "File: $1"
    expand -t 4 "$1" > "$1.tmp"
    mv "$1.tmp" "$1"
}

export -f expand_func

find . -type d \( -path ./src/ASF \) -prune -o -name "*.[ch]" -exec bash -c 'expand_func {}' \;
