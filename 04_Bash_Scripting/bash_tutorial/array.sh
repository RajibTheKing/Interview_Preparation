#!/bin/bash

# an example of array

declare -a arr=("apple" "banana" "cherry")
echo "All values: ${arr[@]}"
echo "Specific value: ${arr[1]}"

# Output:
# All values: apple banana cherry
# Specific value: banana
