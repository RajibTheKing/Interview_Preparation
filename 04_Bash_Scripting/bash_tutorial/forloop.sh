#!/bin/bash

# an example of for loop
arr=("apple" "banana" "cherry")
for item in ${arr[@]}; do
    word_length=$(echo $item | wc -c)
    echo $item $word_length
done

# Output:
# apple 6
# banana 7
# cherry 7
