cmake_minimum_required(VERSION 3.10)
project(FuelManagerApp)

set(CMAKE_CXX_STANDARD 17)

# Include headers
include_directories(include)

# Add all source files from src
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(FuelManagerApp ${SOURCES})
