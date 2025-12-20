#include "file_utils.h"
#include "fuel_manager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>


int main()
{
	// Ensuring data files
	ensureDataFiles();  
	// Declaring a vector for storing fuels
	std::vector<Fuel> fuels;
	// Declaring a vector for storing pumps
	std::vector<Pump> pumps;
	// Declaring a vector for storing information about sale
	std::vector<Sale> sales;
	// Declating a vector for storing delivery information
	std::vector<Delivery> deliveries;
	// Declaring a vector to store information about payment
	std::vector<Payment> payments;
	// Declaring a vector for storing employee's information
	std::vector<Employee> employees =
	{
		{"Alex", "alex123", "emp1", "Fueler"},
		{"Umer", "umer123", "emp2", "Fueler"},
		{"Ali", "ali123", "man1", "Manager"},
		{"Andrew", "andrew123", "own1", "Owner"}
	};

	// Loading sales from the file 
	loadSalesFromFile(sales);

	// Declaring the revenue variable
	double revenue = 0;
	// Running the program 
	runProgram(employees, pumps, fuels, sales, deliveries, payments, revenue);
	return 0;
}



