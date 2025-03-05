# Disk Usage Alert
# Problem: Write a shell script that checks the disk usage of the root filesystem (/).
# If the usage exceeds 80%, print a warning message to the user with the current percentage.
# Bonus: Save the output to a log file with a timestamp.

# Skills Tested: Command substitution, conditionals, piping, working with df.


# Get disk usage of root filesystem
usage=$(df / | awk 'NR==2 {print $5}' | cut -d'%' -f1)
echo "Disk usage: $usage%"
