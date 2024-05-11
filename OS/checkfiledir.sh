#!/bin/bash
check() {
    if [ -f "$1" ]; then
        echo "$1 => is a file."
    elif [ -d "$1" ]; then
        echo "$1 => is a directory."
    else
        echo "$1 => is another type of file."
    fi
}

check "Namaste"
check "jeevan.txt"

