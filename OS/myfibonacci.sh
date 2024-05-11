#!/bin/bash
echo "Enter the number: "
read a
fibo=(0 1)
for ((i=2 ; i<=a ; i++));do
	fibo[i]=$((fibo[i-1]+fibo[i-2]))
done

echo "Fibonacci sequence: "
for x in "${fibo[@]}";do
	echo "$x "
done
