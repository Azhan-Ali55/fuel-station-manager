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
void makeSale(std::vector<Sale>& sales);

// Function to run the program on loop
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Fuel>& fuels, double& revenue);

// Function to calculate daily revenue 
void dailyRev(const std::vector<Sales>& sales, const std::string& date);

// Function to calculate monthly revenue
void monthlyRev(const std::vector<Sale>& sales, int month, int year);

// Function to calculate yearly revenue
void yearlyRev(const std::vector<Sale>& sales, int year);

// Function to calculate all time revenue
void allRev(const std::string<Sale>& sales);

// Function to show the revenue menu
void revMenu(const std::vector<Sale>& sales);
