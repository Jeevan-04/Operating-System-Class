#!/bin/bash

echo "Enter the number:"
read a

if [ $a -le 1 ]; then 
    echo "the number $a is not a prime number"
else
    for ((i = 2 ; i * i <= a ; i++)); do
        if [[ $((a % i)) -eq 0 ]]; then 
            echo "the number $a is not a prime number"
            exit 0
        fi
    done
    echo "the number $a is a prime number"
fi
