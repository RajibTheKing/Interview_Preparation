#!/bin/bash

# an example of sed

# Replace Text (Substitution)
echo "Hello World" | sed 's/World/Bash/'
# Output: Hello Bash


# Replace All Occurrences of a Pattern
echo "apple orange apple" | sed 's/apple/banana/g'
# Output: banana orange banana


# Modify a File Directly (In-Place Editing)
sed -i 's/old/new/g' file.txt
# Replace all occurrences of 'old' with 'new' in file.txt
# -i modifies the file directly without creating a backup.

# Delete specific line in a text file
sed -i '3d' file.txt
# Delete the 3rd line in file.txt

# remove all empty lines in a text file
sed -i '/^$/d' file.txt

# remove everything after line 10 in a text file
sed -i '10,$d' file.txt


