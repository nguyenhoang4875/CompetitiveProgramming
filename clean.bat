@echo off
setlocal enabledelayedexpansion

echo --------------------------------------------------
echo Finding and deleting all .exe files recursively...
echo --------------------------------------------------

:: Loop through the current folder and all subfolders
for /r %%i in (*.exe) do (
    if exist "%%i" (
        :: Print the full path of the file being deleted
        echo Deleting: "%%i"
        
        :: Delete the file (forces deletion of read-only files, deletes quietly)
        del /f /q "%%i"
    )
)

echo --------------------------------------------------
echo Cleanup complete!
echo --------------------------------------------------
pause
