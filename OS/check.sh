#!/bin/bash

# Define a function to check if a number is even or odd
check_even_odd() {
    number=$1
    if (number % 2 = 0)); then
        echo "$number is even"
    else
        echo "$number is odd"
    fi
}

# Call the function with a predefined number
check_even_odd 10

