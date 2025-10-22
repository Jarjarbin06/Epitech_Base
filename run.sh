#!/bin/bash
gcc -o auto_run "$1" -I include/ -L lib/ -lmy
valgrind -s --leak-check=full ./auto_run "$2" "$3" "$4" "$5" "$6"
rm auto_run
