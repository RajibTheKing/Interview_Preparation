#!/bin/bash

case ${1,,} in
    rajib | admin)
        echo "Hey, you are the boss here"
        ;;
    help)
        echo "Just enter your username"
        ;;
    *)
        echo "I don't know you!"
esac
