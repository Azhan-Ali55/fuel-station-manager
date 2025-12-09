#include "fuel_manager.h"
#include <iostream>

int main()
{
    int choice;
    while (true)
    {1
        std::cout << "Enter your choice: \n1) Add Fuel\n2) Exit\n";
        std::cin >> choice;
        switch(choice) {
        case 1:
        std::cout << "The fuel was added succesfully!";
        continue;
        case 2:
        std::cout << "Exiting.....";
        return 0;
        default:
        std::cout << "Invalid Input!";
        continue;
        }
    }
    return 0;
}

