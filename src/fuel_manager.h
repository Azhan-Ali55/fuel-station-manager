#pragma once

#include "structures.h"
#include <string>
#include <vector> 

// Function to add pumps
void addPump(std::vector<Pump>& pumps);

// Function to add fuel
bool addFuel(std::vector<Fuel>& fuels, const std::vector<Pump>& pumps);
