#include "fuel_manager.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>


int main()
{
    // Declaring a vector for storing fuels
    std::vector<Fuel> fuels;
    // Declaring a vector for storing pumps
    std::vector<Pump> pumps;
    int choice;
    while (true)
    {
        std::cout << "Enter your choice: \n1) Add Pump\n2) Add Fuel\n3)Exit\n";
        std::cin >> choice;
        switch(choice) {
        case 1:
        addPump(pumps);
        std::this_thread::sleep_for(std::chrono::seconds(3)); 
        std::cout << "The pump was successfully installed!\n";
        continue;
        case 2:
            if (addFuel(fuels, pumps))
            {
                std::this_thread::sleep_for(std::chrono::seconds(3));
                std::cout << "The fuel was added succesfully!\n";
                continue;
            case 3:
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Exiting.....";
                return 0;
            default:
                std::cout << "Invalid Input!\n";
                continue;
            }
        }
    }
    return 0;
}

// Function defination for adding pumps
void addPump(std::vector<Pump>& pumps)
{
    // Setting maximum pump limit to 6
    if (pumps.size() > 6)
    {
        std::cout << "Maximum pumps have been installed!\n";
        return;
    }

    Pump newPump; // Creating the object of the Pump struct
    std::cout << "Enter the ID of the pump: ";
    std::cin >> newPump.pumpID;
    std::cout << "Enter the fuel type of the pump: ";
    std::cin >> newPump.fuelType;
    std::cin.ignore(); // Clear the input buffer
    pumps.push_back(newPump); // Adds a new pump to the vector 
}
// Function defination for adding fuel
bool addFuel(std::vector<Fuel>& fuels, const std::vector<Pump>& pumps)
{
    if (pumps.size() == 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "No pumps have been installed. Install the pumps first to add fuel\n";
        return false;
    }
    Fuel newFuel; // Creating the object of the Fuel strcut
    std::cout << "Enter fuel name: ";
    std::cin >> newFuel.name;
    std::cout << "Enter fuel price per liter: ";
    std::cin >> newFuel.price;
    std::cout << "Enter the amount of liters: ";
    std::cin >> newFuel.liters;
    std::cin.ignore(); // Clear the input buffer
    fuels.push_back(newFuel); // Adds a new fuel to the vector 
    return true;
}

