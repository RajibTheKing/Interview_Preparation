#!/bin/bash

# some examples of string manipulation

a="hello"
b="world"

# concatenation
c=$a$b
echo $c

# string length
echo ${#c}

# substring
echo ${c:3}

# substring with length
echo ${c:3:4}

# replace
echo ${c/world/rajib}

# replace all, // means all
echo ${c//o/i}

# replace from the beginning
echo ${c/#h/H}

# replace from the end
echo ${c/%rld/RLD}

