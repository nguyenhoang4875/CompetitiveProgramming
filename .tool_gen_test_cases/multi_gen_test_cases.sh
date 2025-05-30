g++ -std=c++17 -o file_solution file_solution.cpp
g++ -std=c++17 -o gen_test_case gen_test_case.cpp

# Config file name and extension name
file_input_name=input
file_output_name=output
ext_in=.txt
ext_out=.txt

# Config parameters in for loop
start_at=0
end_at=9

for ((i = start_at; i <= end_at; i++)); do
    echo $i
    ./gen_test_case > $file_input_name$i$ext_in
    ./file_solution < $file_input_name$i$ext_in > $file_output_name$i$ext_out
done
echo !!! GEN TEST CASES FROM $start_at TO $end_at DONE !!!
