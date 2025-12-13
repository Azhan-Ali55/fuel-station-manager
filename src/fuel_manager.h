#pragma once

#include "structures.h"
#include <string>
#include <vector> 

// Function Prototypes

// Function to add pumps
void addPump(std::vector<Pump>& pumps);

// Function to add fuel
bool addFuel(std::vector<Fuel>& fuels, const std::vector<Pump>& pumps);

// Function for login roles
bool login(Employee &loggedUser, const std::vector<Employee>& employee);

// Function to make sales
void makeSale(double &rev);

// Function to run the program on loop
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Fuel>& fuels, double& revenue);