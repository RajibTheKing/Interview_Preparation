# Problem:  Write a shell script that creates a backup of all .txt files in the current directory.
#             The backup files should be stored in a folder named backup with a timestamp
#             in the format YYYYMMDD_HHMMSS appended to the filename (e.g., file_20250303_123456.txt).
#
# Skills Tested: File manipulation, date command, loops, conditionals.

echo "Creating backup folder..."

dir=./backup

if [ ! -d $dir ]; then
     mkdir $dir
else
     echo "Directory exists"
fi


for file in *.txt; do
    if [ -f "$file" ]; then
        timestamp=$(date +"%Y%m%d_%H%M%S")
        new_file="${file%.*}_${timestamp}.txt"
        cp "$file" "backup/$new_file"
        echo "Backup of $file saved as $new_file"
    fi
done