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

// Function to validate date
bool validDate(const std::string& date);

// Function to make sales
void makeSale(std::vector<Sale>& sales);

// Function to run the program on loop
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Fuel>& fuels, std::vector<Sale>& sales, std::vector<Delivery>& deliveries);

// Function to calculate daily revenue 
double dailyRevenue(const std::string& date);

// Function to calculate monthly revenue
double monthlyRevenue(int month, int year);

// Function to calculate yearly revenue
double yearlyRevenue(int year);

// Function to calculate all time revenue
double allRevenue();

// Function to show the revenue menu
void revenueMenu(const std::vector<Sale>& sales);

// Function to add a new delivery
void addDelivery(std::vector<Delivery>& deliveries);
// Function to show all deliveries
void showDeliveries(const std::vector<Delivery>& deliveries);
