#include "file_utils.h"
#include "fuel_manager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
#include <ctime>


int main()
{
	// Ensuring data files
	ensureDataFiles();  
	
	// Declaring a vector for storing pumps
	std::vector<Pump> pumps;
	
	// Declaring a vector for storing information about sale
	std::vector<Sale> sales;
	
	// Declating a vector for storing delivery information
	std::vector<Delivery> deliveries;
	
	// Declaring a vector for storing expenses 
	std::vector<Expense> expenses;
	
	// Declaring a vector for storing profits
	std::vector<Profit> profits;
	
	// Declaring a vector for storing employee's information
	// These username and passwords are hardcoded and will be used to login into the system 
	std::vector<Employee> employees =
	{
		{"Alex", "alex123", "emp1", "Fueler"},
		{"Umer", "umer123", "emp2", "Fueler"},
		{"Ali", "ali123", "man1", "Manager"},
		{"Andrew", "andrew123", "own1", "Owner"}
	};

	// Declaring a vector for storing stock 
	std::vector<FuelStock> stock =
	{
		{"Petrol", 0, 1500},
		{"Diesel", 0, 500},
		{"Gas", 0, 1000}
	};

	// Loading sales from the file 
	loadSalesFromFile(sales);
	
	// Loading deliveries from the file
	loadDeliveriesFromFile(deliveries);
	
	// Loading expenses from the file
	loadExpensesFromFile(expenses);
	
	// Loading profits from the file
	loadProfitFromFile(profits);
	
	// Loading pumps from the file
	loadPumpFromFile(pumps);

	// Loading stock from the file
	loadStockFromFile(stock);
	
	// Seeding random number generator
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	// Running the program 
	runProgram(employees, pumps, sales, deliveries, expenses, profits, stock);
	return 0;
}



