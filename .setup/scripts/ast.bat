@echo off
setlocal

REM Edit form_path if needed
set "form_path=D:\Repositories\CompetitiveProgramming\.form"

if "%~1"=="" (
  echo Usage: %~nx0 ^<name^>
  exit /b 1
)

set "name=%~1"
set "dest=%CD%\%name%"

if exist "%dest%\" (
  echo Folder "%dest%" already exists!
  exit /b 1
)

mkdir "%dest%" || (echo Cannot create "%dest%" & exit /b 1)

for %%F in (
  _brute.cpp
  _solution.cpp
  analysis.txt
  gen_test_case.cpp
  run_test_case.bat
  stress_test_forCpp.bat
) do (
  if exist "%form_path%\%%F" (
    copy "%form_path%\%%F" "%dest%\" >nul || echo Failed to copy %%F
  ) else (
    echo Source not found: "%form_path%\%%F"
  )
)

echo.
echo Done. Files copied to: "%dest%"
endlocal
exit /b 0
