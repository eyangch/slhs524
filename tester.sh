#!/bin/bash

if [ $# != 4 ]; then
	echo Usage: "$0" "<program 1> <program 2> <generator py file> <iterations>"
	exit
fi

p1="$1"
p2="$2"
gen="$3"
num=$4

for((i = 1; i <= $num; i++)); do
	echo "Testing #$i"
	python3 "$gen" > input_file
	eval "$p1 < input_file > output_1"
	eval "$p2 < input_file > output_2"
	if [ "$(diff output_1 output_2)" != "" ]; then
		echo "You WA uh oh"
		diff output_1 output_2
		exit
	fi
done

echo "You AC maybe"