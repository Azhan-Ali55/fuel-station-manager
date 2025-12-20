#pragma once

#include "structures.h"
#include <vector>
#include <fstream>
#include <filesystem>

// For Sales

// Ensuring that required data files exits 
void ensureDataFiles();

// Function to store the sales to a file 
void saveSaleToFile(const Sale& s);

// Function to load sales from the file
void loadSalesFromFile(std::vector<Sale>& sales);

// For Revenue 

// Fucntion to store the revenue to file 
void saveRevenueToFile(double revenue, const std::string& type, const std::string& identifier = "");

// Function to load the revenue from the file 
double loadRevenueFromFile(const std::string& type, const std::string& identifier = "");

// For Deliveries

// Function to save deliveries to file
void saveDeliveryToFile(const Delivery& d);

// Function to load deliveries from the file
void loadDeliveriesFromFile(std::vector<Delivery>& deliveries);

// For Expenses

// Function to store the expense in the file 
void saveExpenseToFile(const Expense& e);

// Function to load the expenses from the file 
void loadExpensesFromFile(std::vector<Expense>& expenses);

// For Profit report

// Function to store the profit reports in the file 
void saveProfitToFile(const Profit& p);

// Function to load the profit reports from the file 
void loadProfitFromFile(std::vector<Profit>& profits);

