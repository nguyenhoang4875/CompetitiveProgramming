@echo off
g++ -std=c++17 -o _solution.exe _solution.cpp
g++ -std=c++17 -o gen_test_case.exe gen_test_case.cpp

set number_tcs=30
for /l %%x in (1, 1, %number_tcs%) do (
    echo TC %%x:
    gen_test_case > input.in
    _solution < input.in > out_solution.out
    type out_solution.out
)
echo "!!! RUN TEST CASES FINISHED !!!"
