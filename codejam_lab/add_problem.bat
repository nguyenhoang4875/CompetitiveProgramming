@echo off
chcp 65001 >nul

REM === Check if name is passed ===
if "%~1"=="" (
    echo ❌ Usage: add_problem.bat [problem_name]
    pause
    exit /b
)

set name=%~1

REM === Get date MMDD ===
for /f %%a in ('powershell -NoProfile -Command "(Get-Date).ToString('MMdd')"') do set date=%%a

REM === Count folders ===
setlocal enabledelayedexpansion
set count=0
for /d %%D in (*) do (
    set /a count+=1
)

set /a id=%count% + 1
if %id% LSS 10 (
    set id=00%id%
) else if %id% LSS 100 (
    set id=0%id%
)

set folder=%id%_%name%_%date%
mkdir %folder%
type nul > %folder%\%name%.cpp

(
echo PROBLEM SUMMARY:
echo - Task: [Short task description]
echo - Input: [Input format]
echo - Output: [Output format]
echo - Constraints: [Important limits]
echo - Time/Space: [Required complexity]
echo.
echo KEY IDEAS:
echo - [Key idea 1]
echo - [Key idea 2]
echo.
echo APPROACH:
echo - [Algorithm or method]
echo - [Main steps]
echo.
echo EDGE CASES:
echo - [Special cases to watch for]
) > %folder%\%name%_analysis.txt

echo.
echo ✅ Created: %folder%
