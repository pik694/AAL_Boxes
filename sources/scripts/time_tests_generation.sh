#! /bin/bash

problem_sizes=(5 6 7 8 9 10 11 12 20 100 1000 10000 100000)
tests_no=10

for problem_size in ${problem_sizes[*]}; do
    for i in $(seq 1 ${tests_no}); do
        ../../cmake-build-debug/AAL_Boxes -m 0 -s "${problem_size}" -o "tests/time_tests/${problem_size}_${i}" 
    done
done

