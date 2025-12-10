#!/bin/bash
set -e  # Stop the script if any command fails

# Create build folder if it doesn't exist
mkdir -p build
cd build

# Configure the project using CMake
cmake ..

# Build the project
cmake --build .

# Run the executable
# Check common locations for config folders
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
