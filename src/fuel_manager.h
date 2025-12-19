#pragma once

#include "structures.h"
#include <string>
#include <vector> 

// Function Prototypes

// Function to animate the text slowly from left to right 
void animateTxt(std::string text);

// Function to add pumps
void addPump(std::vector<Pump>& pumps);

// Function to add fuel
bool addFuel(std::vector<Fuel>& fuels, const std::vector<Pump>& pumps);

// Function for login roles
bool login(Employee &loggedUser, const std::vector<Employee>& employee);

// Function to make sales
void makeSale(std::vector<Sale>& sales);

// Function to run the program on loop
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Fuel>& fuels, std::vector<Sale>& sales, double& revenue);

// // Function to calculate daily revenue 
// double dailyRev(const std::vector<Sale>& sales, const std::string& date);

// // Function to calculate monthly revenue
// double monthlyRev(const std::vector<Sale>& sales, int month, int year);

// // Function to calculate yearly revenue
// double yearlyRev(const std::vector<Sale>& sales, int year);

// // Function to calculate all time revenue
// double allRev(const std::string<Sale>& sales);

// // Function to show the revenue menu
// void revMenu(const std::vector<Sale>& sales);
