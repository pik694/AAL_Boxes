#! /bin/bash

algorithms=(0)
problem_sizes=(5 6 7 8 9 10 11 12)
tests_no=10


for algorithm in ${algorithms[*]}; do
    for problem_size in ${problem_sizes[*]}; do
        for i in $(seq 1 ${tests_no}); do
            { time ../../cmake-build-debug/AAL_Boxes -m 1 -s "${problem_size}" -a "${algorithm}" ; }  2> "tests/times/${algorithm}_${problem_size}_${i}" 1>&2
        done
    done
done