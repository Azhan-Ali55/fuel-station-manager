#!/bin/bash
cd build

if [ -f Debug/FuelManagerApp ]; then
    ./Debug/FuelManagerApp
elif [ -f Release/FuelManagerApp ]; then
    ./Release/FuelManagerApp
elif [ -f FuelManagerApp ]; then
    ./FuelManagerApp
else
    echo "Executable not found!"
    exit 1
fi
