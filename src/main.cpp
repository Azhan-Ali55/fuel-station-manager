#include "fuel_manager.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>


int main()
{
	// Declaring a vector for storing fuels
	std::vector<Fuel> fuels;
	// Declaring a vector for storing pumps
	std::vector<Pump> pumps;
	// Declaring a vector for storing employee's information
	std::vector<Employee> emp =
	{
		{"Alex", "alex123", "emp1", "Fueler"},
		{"Umer", "umer123", "emp2", "Fueler"},
		{"Ali", "ali123", "man1", "Manager"},
		{"Andrew", "andrew123", "own1", "Owner"}
	};
	// Declaring the revenue variable
	double revenue = 0;
	int choice;
	Employee loggedId;
	while (true)
	{
		while (true)
		{
			if (login(loggedId, emp))
				break;
		}
		std::cout << "Enter your choice: \n1) Add Pump\n2) Add Fuel\n3) Sell\n4) Exit\n";
		std::cin >> choice;
		switch (choice)
		{
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
			}
		case 3: 
			makeSale(revenue);
			continue;
		case 4:
			std::cout << "Exiting.....";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return 0;
		default:
			std::cout << "Invalid Input!\n";
			continue;
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

// Function defination for login roles
bool login(Employee& loggedUser, const std::vector<Employee>& employee)
{
	// Declaring variables for username and password
	std::string userName;
	std::string pass;
	std::cout << "Enter username: ";
	std::cin >> userName;
	// Applying loop to check for username and password
	for (int i = 0; i < employee.size(); i++)
	{
		Employee emp = employee[i]; // Assigning the copy of vector to emp
		// Apply conditions to check for correct username
		if (emp.username == userName)
		{
			// Ask password if the username is correct
			std::cout << "Enter password: ";
			std::cin >> pass;
			// Check if password is correct
			if (emp.password == pass)
			{
				loggedUser = emp;
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "\nWelcome " << emp.name << '\n';
				return true;
			}
			else
			{
				std::cout << "Incorrect password! Try Again\n";
				return false;
			}
		}
	}
	std::cout << "Incorrect username! Try Again\n";
	return false;
}

// Function defination for making sale
void makeSale(double &rev)
{
	Sale sales; // Making object for Sale struct 
	std::cout << "Enter the fuel: ";
	std::cin >> sales.fuel;
	std::cout << "Enter the liters: ";
	std::cin >> sales.liters;
	std::cout << "Enter the price per liter: ";
	std::cin >> sales.price;
	std::cout << "Enter the date: ";
	std::cin >> sales.date;
	rev = sales.price * sales.liters;
	// Generating the reciept
	std::cout << "===============================================\n";
	std::cout << "                     RECIEPT                   \n";
	std::cout << "===============================================\n";
	std::cout << "Fuel: " << std::setw(3) << sales.fuel << '\n';
	std::cout << "Liters Sold: " << std::setw(3) << sales.liters << '\n';
	std::cout << "Total price: " << std::setw(3) << rev << '\n';
	std::cout << "Date: " << sales.date << '\n';
}

