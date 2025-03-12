@echo off
g++ -std=c++17 -o _solution.exe _solution.cpp
g++ -std=c++17 -o _brute.exe _brute.cpp
g++ -std=c++17 -o gen_test_case.exe gen_test_case.cpp

set number_tcs=100
for /l %%x in (1, 1, %number_tcs%) do (
    echo TC %%x:
    gen_test_case > input.in
    _brute < input.in > out_brute.out 
    _solution < input.in > out_solution.out
    fc out_brute.out out_solution.out > diff_file.txt || (
        echo WA on TC: %%x
        echo. 
        type input.in
        echo.
        echo Expected:
        type out_brute.out
        echo.
        echo Actual:
        type out_solution.out
        exit /b
    )
)
echo "!!! ALL TESTS PASSED !!!"
