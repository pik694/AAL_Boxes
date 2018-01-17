#!/bin/bash

for i in tests/correctness_tests/*.in ; do
    test=${i%.*}
    echo -n "Running test ${test} : "
    ../../cmake-build-debug/AAL_Boxes -m 2 -i "${test}.in" -o "out.out" -a 1
    awk '(NR==FNR && FNR==2) {result[$0]++; nextfile} ; {if(!($0 in result) && FNR==2) exit 1 }' "${test}.out" out.out 
    if [ "${?}" -ne "0" ]; then
        echo "failed"
        exit 1
    else
        echo "passed"
    fi  

done 

rm out.out