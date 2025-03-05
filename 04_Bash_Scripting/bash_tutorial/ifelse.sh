#!/bin/bash

if [ ${1,,} = rajib ]; then
	echo "Hey, you are the boss here"
elif [ ${1,,} = help ]; then
	echo "Man! just hit your username"
else
	echo "I don't know you!"
fi
