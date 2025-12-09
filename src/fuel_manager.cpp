#include "fuel_manager.h";
#include <iostream>
#include <vector>

// Declaring a global vector
std::vector<Fuel> fuels;

// Function defination for adding fuel
void addFuel()
{
    Fuel newFuel;
    std::cout << "Enter fuel name: ";
    std::cin >> newFuel.name;
    std::cout << "Enter fuel price per liter: ";
    std::cin >> newFuel.price;
    std::cout << "Enter the amount of liters: ";
    std::cin >> newFuel.liters;
    std::cin.ignore(); // Clear the input buffer
    fuels.push_back(newFuel); // Creates a new container at the end of the list of fuels
}