#!/bin/bash
cd lib/my
printf "\n\033[32m./lib/my/ :\033[0m\n"
epiclang *.c
cd ../../ tests
printf "\n\033[32m./tests/ :\033[0m\n"
epiclang *.c
cd ..
printf "\n\033[32m./ :\033[0m\n"
epiclang *.c
