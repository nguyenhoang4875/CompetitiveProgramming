g++ -std=c++17 -o file_solution file_solution.cpp
g++ -std=c++17 -o file_brute file_brute.cpp

number_tcs=100
for ((i = 1; i <= number_tcs; i++)); do
    echo $i
    python gen_testcase.py > input.in
    ./file_brute < input.in > out_brute.out
    ./file_solution < input.in > out_solution.out

    # Bash Magic 🤩 : If the difference command produces any output
    if [[ $(diff out_brute.out out_solution.out) ]]
    then
        # 🤩 map the output of diff command to difference_file
        echo "$(diff -Z out_brute.out out_solution.out)" > diff_file.txt
        echo "WA on TC: $i"
        echo
        cat input.in
        echo "Expeted: "
        cat out_brute.out
        echo
        echo "Actual: "
        cat out_solution.out
    
        # echo "--------------------------------------------------------"
        # 🤐 Once the difference is found and we've reported it and then break right here
        break
    else
        echo "AC on TC $i"
    fi

    if [ $i -eq $number_tcs ]; then
        echo "!!! ALL TESTS PASSED !!!"
    fi

done
