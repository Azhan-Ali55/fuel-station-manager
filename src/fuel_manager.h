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
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Fuel>& fuels, std::vector<Sale>& sales, std::vector<Delivery>& deliveries, std::vector<Expense>& expenses, std::vector<Profit>& profits);

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

// Function to add daily expenses
void setDailyExpense(std::vector<Expense>& expenses);

// Functions to calculate expenses
double dailyExpense(const std::string& date);
double monthlyExpense(int month, int year);
double yearlyExpense(int year);
double totalExpense();

// Function for Expense menu
void expensesMenu(std::vector<Expense>& expenses);

// Function to calculate profits 
double dailyProfit(const std::string& date);
double monthlyProfit(int month, int year);
double yearlyProfit(int year);
double totalProfit();

// Function for profit menu
void profitMenu(std::vector<Profit>& profits);
