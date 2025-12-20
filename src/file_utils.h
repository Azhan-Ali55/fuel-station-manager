#pragma once

#include "file_utils.h"
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

