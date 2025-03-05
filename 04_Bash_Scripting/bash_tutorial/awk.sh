#!/bin/bash

# an example of awk

echo one two three > temp.txt
awk '{print $1}' temp.txt
awk '{print $2}' temp.txt

echo "Just get this word: Hello" | awk '{print $5}'
echo "Just get this word: Hello" | awk -F: '{print $1}'
echo "Just get this word: Hello" | awk -F: '{print $2}'
echo "Just get this word: Hello" | awk -F: '{print $2}' | cut -d' ' -f2

# Output:
# one
# two
# Hello
# Just get this word
#  Hello
# Hello