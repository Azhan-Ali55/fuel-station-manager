#pragma once

#include "file_utils.h"
#include "structures.h"
#include <vector>
#include <fstream>
#include <filesystem>

// Ensuring that required data files exits 
void ensureDataFiles();

// Function to store the sales to a file 
void saveSaleToFile(const Sale& s);

// Function to load sales from the file
void loadSalesFromFile(std::vector<Sale>& sales);