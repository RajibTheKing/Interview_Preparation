#!/bin/bash

# an example of function
function greet() {
    echo "Hello, $1 $2"
}

sum_of_two_numbers() {
    local sum=$(($1 + $2))
    return $sum
}

# function without return value
greet "Rajib" "Das"

# function with return value
sum_of_two_numbers 10 20
ans=$?
echo "Sum of two numbers: $ans"

# Output:
# Hello, Rajib Das
# Sum of two numbers: 30
