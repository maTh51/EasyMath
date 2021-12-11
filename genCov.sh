#!/bin/bash
mkdir coverage
g++ -o coverage/cov -fprofile-arcs -ftest-coverage tests/EasyMath.cpp -lgtest -Ilib
./coverage/cov
cd coverage
mkdir reports
cd reports
gcov ../../tests/EasyMath.cpp -o ../cov-EasyMath.gc
lcov -d .. -c --directory . --output-file coverage.info