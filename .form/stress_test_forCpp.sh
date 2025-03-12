g++ -std=c++17 -o _solution _solution.cpp
g++ -std=c++17 -o _brute _brute.cpp
g++ -std=c++17 -o gen_testcase gen_testcase.cpp

number_tcs=100
for ((i = 1; i <= number_tcs; i++)); do
    echo TC $i:
    ./gen_testcase > input.in
    ./_brute < input.in > out_brute.out
    ./_solution < input.in > out_solution.out

    # Bash Magic 🤩 : If the difference command produces any output
    if [[ $(diff out_brute.out out_solution.out) ]]
    then
        # 🤩 map the output of diff command to difference_file
        echo "$(diff -Z out_brute.out out_solution.out)" > diff_file.txt
        echo "WA on TC: $i"
        echo
        cat input.in
        echo "Expected: "
        cat out_brute.out
        echo
        echo "Actual: "
        cat out_solution.out
    
        # echo "--------------------------------------------------------"
        # 🤐 Once the difference is found and we've reported it and then break right here
        break
    fi

    if [ $i -eq $number_tcs ]; then
        echo "!!! ALL TESTS PASSED !!!"
    fi

done
