@echo off
cd build

REM Check Debug folder first
if exist Debug\FuelManagerApp.exe (
    Debug\FuelManagerApp.exe
) else if exist Release\FuelManagerApp.exe (
    Release\FuelManagerApp.exe
) else (
    echo Executable not found!
)

pause
