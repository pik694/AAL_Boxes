#! /bin/bash

output_path="./tests/correctness_tests/"
tests_no=10
tests_sizes=(1 2 3 4 5 6 7 8 9 10 11 12)

#Generate test cases and solve them using brut force algorithm
for test_size in ${tests_sizes[*]}; do
    for i in $(seq 1 $tests_no);do
        echo -n "Generating test ${test_size}_${i} : "
        ../../cmake-build-debug/AAL_Boxes -m 0 -o "${output_path}/${test_size}_${i}.in" -s ${test_size}
        echo "done"
        echo -n "Computing result of test ${test_size}_${i} : "
        ../../cmake-build-debug/AAL_Boxes -m 2 -i "${output_path}/${test_size}_${i}.in" -o "${output_path}/${test_size}_${i}.out"
        echo "done"
    done
done

