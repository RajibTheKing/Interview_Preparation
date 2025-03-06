#!/bin/bash

# an example  echo styling

echo -e "\e[1;31mThis is red text\e[0m"
echo -e "\e[1;32mThis is green text\e[0m"
echo -e "\e[1;33mThis is yellow text\e[0m"
echo -e "\e[1;34mThis is blue text\e[0m"
echo -e "\e[1;35mThis is magenta text\e[0m"
echo -e "\e[1;36mThis is cyan text\e[0m"
echo -e "\e[1;37mThis is white text\e[0m"

# print ERROR message, where ERROR is blinking
flashred="\e[5;31;40m"
red="\e[31;40m"
none="\e[0m"
echo -e $flashred"ERROR: "$none$red"Something went wrong"$none


# using tput
flashred=$(tput setab 0; tput setaf 1; tput blink)
red=$(tput setab 0; tput setaf 1)
none=$(tput sgr0)
echo -e $flashred"ERROR: "$none$red"Something went wrong"$none
