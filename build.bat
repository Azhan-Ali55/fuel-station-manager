@echo off
if not exist build mkdir build
cd build

cmake ..
cmake --build .

REM Run executable in Debug or Release
if exist Debug\FuelManagerApp.exe (
    Debug\FuelManagerApp.exe
) else if exist Release\FuelManagerApp.exe (
    Release\FuelManagerApp.exe
) else (
    echo Build succeeded but executable not found!
)

pause
