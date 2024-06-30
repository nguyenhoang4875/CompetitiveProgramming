@echo off
g++ -std=c++17 -o file_solution.exe file_solution.cpp
g++ -std=c++17 -o file_brute.exe file_brute.cpp
g++ -std=c++17 -o gen_testcase.exe gen_testcase.cpp

set number_tcs=100
for /l %%x in (1, 1, %number_tcs%) do (
    echo TC %%x:
    gen_testcase > input.in
    file_brute < input.in > out_brute.out 
    file_solution < input.in > out_solution.out
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
pause
