#! /bin/bash

    algorithms=(1)
    problem_sizes=(100 1000)
    tests_no=10


    for algorithm in ${algorithms[*]}; do
        for problem_size in ${problem_sizes[*]}; do
            for i in $(seq 1 ${tests_no}); do
                { time ../../cmake-build-debug/AAL_Boxes -m 1 -s "${problem_size}" -a "${algorithm}" ; }  2> "tests/time_tests/${algorithm}_${problem_size}_${i}" 1>&2
            done
        done
    done