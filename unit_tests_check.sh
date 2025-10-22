#!/bin/bash
./clear.sh
cd lib/my
./../../clear.sh
cd ../../tests
./../clear.sh
cd ../include
./../clear.sh
cd ..

gcc -o unit_tests lib/my/*.c tests/*.c -I include/ -L lib/ --coverage -lcriterion
./unit_tests
gcovr * -e tests

./clear.sh
