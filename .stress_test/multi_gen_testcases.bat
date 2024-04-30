@echo off
g++ -std=c++17 -o file_solution.exe file_solution.cpp

rem Config file name and extension name
set file_input_name=input
set file_output_name=output
set ext_in=.txt
set ext_out=.txt

rem Config parameters in for loop
set start_at=0
set end_at=9

for /l %%x in (%start_at%, 1,%end_at%) do (
    echo %%x
    python gen_testcase.py > %file_input_name%%%x%ext_in%
    file_solution < %file_input_name%%%x%ext_in% > %file_output_name%%%x%ext_out%
)
echo !!! GEN TEST CASES FROM %start_at% TO %end_at% DONE !!!
pause
