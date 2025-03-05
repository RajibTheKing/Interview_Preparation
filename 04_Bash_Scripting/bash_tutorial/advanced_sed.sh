# Multiple Replacements in One Command
sed 's/World/Bash/g; s/apple/banana/g' file.txt
# Output: Hello Bash orange banana

# Case-Insensitive Search and Replace
sed 's/World/Bash/Ig' file.txt

# If you want a backup before modifying:
sed -i.bak 's/World/Bash/g' file.txt

# Extract text between <start> and <end> tags:
sed -n '/<start>/,/<end>/p' file.txt

# examples of combing sed with grep
grep "error" log.txt | sed 's/error/ERROR/g'
grep "error" log.txt | sed 's/error/ERROR/g' > error_log.txt
grep "error" log.txt | sed 's/error/ERROR/g' | sed 's/warning/WARNING/g' > error_log.txt
grep "error" log.txt | sed 's/error/ERROR/g; s/warning/WARNING/g' > error_log.txt

