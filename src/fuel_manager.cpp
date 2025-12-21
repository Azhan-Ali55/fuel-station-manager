#include "file_utils.h"
#include "fuel_manager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Function defination for running the program
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Sale>& sales, std::vector<Delivery>& deliveries, std::vector<Expense>& expenses, std::vector<Profit>& profits, std::vector<FuelStock>& stock)
{
	int choice;
	Employee loggedUser;
	bool loggedIn = false;
	while (true)
	{
		while (!loggedIn)
		{
			if (login(loggedUser, employees))
				loggedIn = true;
		}

		// Give access based on roles

		// For owner
		if (loggedUser.role == "Owner")
		{
			std::cout << "Enter your choice: \n1) Add Pump\n2) Add Fuel\n3) Sell\n4) Order Fuel\n5) Revenue Report\n6) Expense Report\n7) Profit Report\n8) Pump status\n9) Repair Pump\n10) Log out\n11) Exit\n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				addPump(pumps);
				std::this_thread::sleep_for(std::chrono::seconds(3));
				std::cout << "The pump was successfully installed!\n";
				continue;
			}
			case 2:
			{
				refillPump(pumps, stock);
				continue;
			}
			case 3:
			{
				makeSale(sales, pumps);
				continue;
			}
			case 4:
			{
				addDelivery(deliveries, expenses, stock);
				continue;
			}
			case 5:
			{
				revenueMenu(sales);
				continue;
			}
			case 6:
			{
				setDailyExpense(expenses);
				expensesMenu(expenses);
				continue;
			}
			case 7:
			{
				profitMenu(profits);
				continue;
			}
			case 8:
			{
				pumpsStatus(pumps);
				continue;
			}
			case 9:
			{
				repairPump(pumps);
				continue;
			}
			case 10:
			{
				loggedIn = false;
				loggedUser = Employee{};
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "Logged out successfully!\n";
				continue;
			}
			case 11:
			{
				std::cout << "Exiting.....";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return;
			}
			default:
			{
				std::cout << "Invalid Input!\n";
				continue;
			}
			
			}
		}

		// For Manager
		else if (loggedUser.role == "Manager")
		{
			std::cout << "Enter your choice: \n1) Add Fuel\n2) Sell\n3) Order Fuel\n4) Expense Report\n5) Pump Status\n6) Repair Pump\n7) Log out\n8) Exit\n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				refillPump(pumps, stock);
				continue;
			}
			case 2:
			{
				makeSale(sales, pumps);
				continue;
			}
			case 3:
			{
				addDelivery(deliveries, expenses, stock);
				continue;
			}
			case 4:
			{
				setDailyExpense(expenses);
				expensesMenu(expenses);
				continue;
			}
			case 5:
			{
				pumpsStatus(pumps);
				continue;
			}
			case 6: 
			{
				repairPump(pumps);
				continue;
			}
			case 7:
			{
				loggedIn = false;
				loggedUser = Employee{};
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "Logged out successfully!\n";
				continue;
			}
			case 8:
			{
				std::cout << "Exiting.....";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return;
			}
			default:
			{
				std::cout << "Invalid Input!\n";
				continue;
			}

			}
		}

		// For Fueler
		else
		{
			std::cout << "Enter your choice:\n1) Add Fuel\n2) Sell\n3) Repair Pump\n4) Log out\n5) Exit\n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				refillPump(pumps, stock);
				continue;
			}
			case 2:
			{
				makeSale(sales, pumps);
				continue;
			}
			case 3:
			{
				repairPump(pumps);
				continue;
			}
			case 4:
			{
				loggedIn = false;
				loggedUser = Employee{};
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "Logged out successfully!\n";
				continue;
			}
			case 5:
			{
				std::cout << "Exiting.....";
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return;
			}
			default:
			{
				std::cout << "Invalid Input!\n";
				continue;
			}

			}
		}
	}
}

// Function defination for adding pumps
void addPump(std::vector<Pump>& pumps)
{
	// Setting maximum pump limit to 6
	if (pumps.size() >= 6)
	{
		std::cout << "Maximum pumps have been installed!\n";
		return;
	}

	Pump p; // Creating the object of the Pump struct
	std::cout << "Enter the ID of the pump: ";
	std::cin >> p.pumpID;

	// Ensure no duplicate Id exists
	for (int i = 0; i < pumps.size(); i++)
	{
		if (pumps[i].pumpID == p.pumpID)
		{
			std::cout << "A pump with this ID is already installed! Try Again\n";
			return;
		}
	}

	std::cout << "Enter the fuel type of the pump: ";
	std::cin >> p.fuelType;
	std::cin.ignore(); // Clear the input buffer

	// Initializing pump information
	p.maxCapacity = 500;
	p.currentLiters = 500;    
	p.dispensedLiters = 0;
	p.malfunc = false;
	p.leak = false;
	pumps.push_back(p); // Adds a new pump to the vector 
	savePumpToFile(p);
}

// Function defination for refilling the pump
void refillPump(std::vector<Pump>& pumps, std::vector<FuelStock>& stock)
{
	int id;
	std::cout << "Enter pump ID: ";
	std::cin >> id;

	// Check if pump exists
	for (int i = 0; i < pumps.size(); i++)
	{
		if (pumps[i].pumpID == id)
		{
			// Find stock for this fuel 
			for (int j = 0; j < stock.size(); j++)
			{
				// Check if pump type matches the type in stck 
				if (pumps[i].fuelType == stock[j].fuelType)
				{
					if (stock[j].currentLiters <= 0)
					{
						std::cout << "The stock is empty! Refill stock to fill the pump\n";
						return;
					}

					// Now we calculate the max fuel that can be filled in the pump
					int maxFuel = std::min(pumps[i].maxCapacity - pumps[i].currentLiters, stock[j].currentLiters);
					pumps[i].currentLiters += maxFuel;
					stock[j].currentLiters -= maxFuel;

					// Save stock to file 
					saveStockToFile(stock);
					std::cout << "Pump refilled by " << maxFuel << " liters from the stock.\n";
					return;
				}
			}

			std::cout << "Stock for this fuel not found!\n";
			return;
		}
	}

	std::cout << "Pump not found!\n";
}

// Function defination for fixing the pump
void repairPump(std::vector<Pump>& pumps)
{
	int id;
	std::cout << "Enter pump ID to repair: ";
	std::cin >> id;

	for (int i = 0; i < pumps.size(); i++)
	{
		if (pumps[i].pumpID == id)
		{
			if (!pumps[i].malfunc)
			{
				std::cout << "Pump is already operational\n";
				return;
			}

			pumps[i].malfunc = true;
			pumps[i].leak = false;
			std::cout << "Pump repaired successfully\n";
			return;
		}
	}

	std::cout << "Invalid pump ID! Try Again\n";
}

// Function defination for viewing pump status
void pumpsStatus(std::vector<Pump>& pumps)
{
	if (pumps.size() == 0)
	{
		std::cout << "No pumps have been installed\n";
		return;
	}

	std::cout << "==================== PUMP STATUS ====================\n";
	for (int i = 0; i < pumps.size(); i++)
	{
		std::cout << "Pump ID: " << pumps[i].pumpID << '\n';
		std::cout << "Fuel Type: " << pumps[i].fuelType << '\n';
		std::cout << "Current Liters: " << pumps[i].currentLiters << '\n';
		std::cout << "Total Dispensed Liters: " << pumps[i].dispensedLiters << '\n';
		std::cout << "Max Capacity: " << pumps[i].maxCapacity << '\n';
		std::cout << "Malfunction: " << (pumps[i].malfunc ? "Yes" : "No") << '\n';
		std::cout << "Leak: " << (pumps[i].leak ? "Yes" : "No") << '\n';
		std::cout << "-----------------------------------------------------\n";
	}
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
		// Apply conditions to check for correct username
		if (employee[i].username == userName)
		{
			// Ask password if the username is correct
			std::cout << "Enter password: ";
			std::cin >> pass;
			// Check if password is correct
			if (employee[i].password == pass)
			{
				loggedUser = employee[i];
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "\nWelcome " << employee[i].name << '\n';
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

// Function defination to validate date
bool validDate(const std::string& date)
{
	if (date.size() == 10 && date[2] == '-' && date[5] == '-')
		return true;
	else
		return false;
}

// Function defination for making sale
void makeSale(std::vector<Sale>& sales, std::vector<Pump>& pumps)
{
	int pumpID;
	std::cout << "Enter pump ID: ";
	std::cin >> pumpID;

	// Check if pump exists
	int pumpIndex = -1;
	for (int i = 0; i < pumps.size(); i++)
	{
		if (pumps[i].pumpID == pumpID)
		{
			pumpIndex = i;
			break;
		}
	}

	if (pumpIndex == -1)
	{
		std::cout << "Invalid Pump ID! Try again\n";
		return;
	}

	Pump& pump = pumps[pumpIndex];
	if (pump.malfunc)
	{
		std::cout << "Pump malfunctioned.\n";
		return;
	}

	if (pump.currentLiters <= 0)
	{
		std::cout << "Pump empty.\n";
		return;
	}

	Sale s;
	s.pumpId = pump.pumpID;
	s.fuel = pump.fuelType;
	std::cout << "Enter the liters: ";
	std::cin >> s.liters;
	if (s.liters > pump.currentLiters)
	{
		std::cout << "Not enough fuel in the pump! Refill and Try again\n";
		return;
	}
	
	if (s.fuel == "Petrol")
		s.price = 280;
	else if (s.fuel == "Diesel")
		s.price = 300;
	else if (s.fuel == "Gas")
		s.price = 250;
	else
	{
		std::cout << "Invalid Input! Try again\n";
		return;
	}

	// Validating date do that it is in DD-MM-YYYY format
	int day, month, year;
	char dash1, dash2;
	std::cout << "Enter the date (DD-MM-YYYY): ";
	std::cin >> day >> dash1 >> month >> dash2 >> year;
	std::ostringstream oss;
	oss << std::setw(2) << std::setfill('0') << day << "-"
		<< std::setw(2) << std::setfill('0') << month << "-"
		<< year;
	s.date = oss.str();

	// Random malfunction and leakage chnace
	srand(time(0));
	int chance = rand() % 100;
	if (chance < 5)
	{
		pump.malfunc = true;
		std::cout << "Pump malfunctioned during sale.\n";
		return;
	}
	else if (chance < 10)
	{
		pump.leak = true;
		int leakAmount = rand() % 51 + 5;
		pump.currentLiters -= leakAmount;
		if (pump.currentLiters < 0) 
			pump.currentLiters = 0;
		std::cout << "Leak detected! " << leakAmount << " liters lost\n";
	}

	pump.currentLiters -= s.liters;
	pump.dispensedLiters += s.liters;
	// Calculating total
	s.totalAmount = s.price * s.liters;

	// Handling payment method
	std::cout << "Enter payment method(Cash/Card/Online): ";
	std::cin >> s.payment.method;

	sales.push_back(s);  // Stores the sale and creates new storage location in the vector
	saveSaleToFile(s);   // Calling function to save the sale

	// Generating the reciept
	std::cout << "\n=========== RECEIPT ===========\n";
	std::cout << "Pump ID: " << s.pumpId << '\n';
	std::cout << "Fuel: " << s.fuel << '\n';
	std::cout << "Liters: " << s.liters << '\n';
	std::cout << "Price/L: " << s.price << '\n';
	std::cout << "Total: " << s.totalAmount << '\n';
	std::cout << "Paid by: " << s.payment.method << '\n';
	std::cout << "Date: " << s.date << '\n';
	std::cout << "===============================\n";
}

// Function  defination for animating text
void animateTxt(std::string text)
{
	for (int i = 0; i < text.size(); i++)
	{
		char c = text[i]; // Strong one chracter from the text 
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << std::endl;
}
// Function to add a new delivery
void addDelivery(std::vector<Delivery>& deliveries, std::vector<Expense>& expenses, std::vector<FuelStock>& stock)
{
	Delivery d;
	std::cout << "------------------------\n";
	std::cout << "  Give Delivery Details \n";
	std::cout << "------------------------\n";
	std::cout << "Enter fuel type: ";
	std::cin >> d.fuel;
	std::cout << "Enter delivery date(DD-MM-YYYY): ";
	std::cin >> d.date;
	std::cout << "Enter liters: ";
	std::cin >> d.litersDelivered;

	double costPerLiter = 0.0;
	if (d.fuel == "Petrol")
		costPerLiter = 120;
	else if (d.fuel == "Diesel")
		costPerLiter = 140;
	else if (d.fuel == "Gas")
		costPerLiter = 90;
	else
	{
		std::cout << "Invalid Input! Try again\n";
		return;
	}

	// Calculate the total delivery cost and storing it
	d.deliveryCost = d.litersDelivered * costPerLiter;
	// Update stock
	bool stockUpdated = false;
	for (int i = 0; i < stock.size(); i++) 
	{
		if (stock[i].fuelType == d.fuel) 
		{
			if (stock[i].currentLiters + d.litersDelivered > stock[i].maxCapacity) 
			{
				std::cout << "Cannot add delivery. Stock would exceed max capacity!\n";
				return;
			}
			stock[i].currentLiters += d.litersDelivered;
			stockUpdated = true;
			break;
		}
	}

	if (!stockUpdated) 
	{
		std::cout << "No stock found for this fuel type!\n";
		return;
	}

	// Sace stock and delivery
	saveStockToFile(stock); 
	deliveries.push_back(d);
	saveDeliveryToFile(d);

	// Record delivery as expense
	Expense e;
	e.type = "Delivery";
	e.amount = d.deliveryCost;
	e.date = d.date;
	expenses.push_back(e);
	saveExpenseToFile(e);

	std::cout << "Delivery succesfully added to stock!\n";
}

// Function to show all deliveries
void showDeliveries(const std::vector<Delivery>& deliveries)
{
	if (deliveries.size() == 0)
	{
		std::cout << "No deliveries recorded yet.\n";
		return;
	}
	for (int i = 0; i < deliveries.size(); i++)
	{
		std::cout << "\n================\n";
		std::cout << "Delivery Status\n";
		std::cout << "================\n";
		std::cout << "Delivery " << i + 1 << '\n';
		std::cout << "Fuel: " << deliveries[i].fuel << '\n';
		std::cout << "Date: " << deliveries[i].date << '\n';
		std::cout << "Liters Delivered: " << deliveries[i].litersDelivered << '\n';
		std::cout << "Cost: " << deliveries[i].deliveryCost << '\n';
	}
}

// Function defination for calculating daily revenue 
double dailyRevenue(const std::string& date)
{
	std::ifstream file("data/sales.txt");
	
	// if file does not exist return 0
	if (!file)
	{
		return 0.0;
	}

	double revenue = 0.0;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string saleDate, fuel, paymentMethod;
		double liters, price, totalAmount;

		iss >> saleDate >> fuel >> liters >> price >> totalAmount >> paymentMethod;

		if (saleDate == date)
		{
			revenue += totalAmount;
		}
	}

	return revenue;
}

// Function defination for calculating monthly revenue 
double monthlyRevenue(int month, int year)
{
	std::ifstream file("data/sales.txt");
	
	// if file does not exist return 0
	if (!file)
	{
		return 0.0;
	}

	double revenue = 0.0;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string saleDate, fuel, paymentMethod;
		double liters, price, totalAmount;
		iss >> saleDate >> fuel >> liters >> price >> totalAmount >> paymentMethod;

		int saleMonth = std::stoi(saleDate.substr(3, 2));
		int saleYear = std::stoi(saleDate.substr(6, 4));

		if (saleMonth == month && saleYear == year)
		{
			revenue += totalAmount;
		}
	}

	return revenue;
}

// Function defination for calculating yearly revenue
double yearlyRevenue(int year)
{
	std::ifstream file("data/sales.txt");
	if (!file)
	{
		return 0.0;
	}
	double revenue = 0.0;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string saleDate, fuel, paymentMethod;
		double liters, price, totalAmount;
		iss >> saleDate >> fuel >> liters >> price >> totalAmount >> paymentMethod;

		int saleYear = std::stoi(saleDate.substr(6, 4));
		if (saleYear == year)
		{
			revenue += totalAmount;
		}
	}

	return revenue;
}

// Function defination for calculating all time revenue
double allRevenue()
{
	std::ifstream file("data/sales.txt");
	if (!file) return 0.0;

	double revenue = 0.0;
	std::string line;
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string saleDate, fuel, paymentMethod;
		double liters, price, totalAmount;
		iss >> saleDate >> fuel >> liters >> price >> totalAmount >> paymentMethod;

		revenue += totalAmount;
	}

	return revenue;
}

// Function to display the menu for revenue 
void revenueMenu(const std::vector<Sale>& sales)
{
	std::cout << "===============================\n";
	std::cout << "              Revenue          \n";
	std::cout << "===============================\n";

	int choice;
	std::cout << "1) Daily Revenue\n2) Monthly Revenue\n3) Yearly Revenue\n4) All-Time Revenue\n5) Back\n";
	std::cin >> choice;

	// Using switch to display revenue 
	switch (choice)
	{
	case 1:
	{
		std::string date;
		std::cout << "Enter date (DD-MM-YYYY): ";
		std::cin >> date;
		
		// Validate date
		if (!validDate(date)) 
		{
			std::cout << "Invalid date format!\n";
			return;
		}

		double revenue = loadRevenueFromFile("daily", date);
		// If not file then calculate and save
		if (revenue == 0.0) 
		{
			revenue = dailyRevenue(date);
			saveRevenueToFile(revenue, "daily", date);
		}

		std::cout << "Revenue on " << date << ": " << revenue << "\n";
		break;
	}
	case 2:
	{
		int month, year;
		std::cout << "Enter month (1-12): ";
		std::cin >> month;
		std::cout << "Enter year: ";
		std::cin >> year;

		// Validate month and year
		if (month < 1 || month > 12 || year < 2000 || year > 2025)
		{
			std::cout << "Invalid month/year!\n";
			return;
		}

		// Ensures that month has 2 digits 
		std::string identifier = (month < 10 ? "0" : "") + std::to_string(month) + "-" + std::to_string(year);

		double revenue = loadRevenueFromFile("monthly", identifier);
		// If not file then calculate and save
		if (revenue == 0.0)
		{
			revenue = monthlyRevenue(month, year);
			saveRevenueToFile(revenue, "monthly", identifier);
		}
		std::cout << "Revenue for " << month << " in " << year << " is: " << revenue << "\n";
		break;
	}
	case 3:
	{
		int year;
		std::cout << "Enter year: ";
		std::cin >> year;
		std::string identifier = std::to_string(year);
		double revenue = loadRevenueFromFile("yearly", identifier);
		// If not file then calculate and save
		if (revenue == 0.0)
		{
			revenue = yearlyRevenue(year);
			saveRevenueToFile(revenue, "yearly", identifier);
		}
		std::cout << "Revenue for " << year << ": " << revenue << "\n";
		break;
	}
	case 4:
	{
		double revenue = loadRevenueFromFile("all-time");
		// If not file then calculate and save
		if (revenue == 0.0) 
		{
			revenue = allRevenue();      
			saveRevenueToFile(revenue, "all-time");
		}
		std::cout << "All-Time revenue: " << revenue << "\n";
		break;
	}
	case 5:
	{
		return;
	}
	default:
	{
		std::cout << "Invalid Input!";
	}

	}
}

// Function defination for daily expenses
void setDailyExpense(std::vector<Expense>& expenses)
{
	// Creating objects for Expense
	Expense s;
	Expense e;
	Expense d;

	// Initializing the cost for each

	// For salary
	s.type = "Salary";
	s.date = "01-01-2025";
	s.amount = 1000.0;

	// For electricity bill
	e.type = "Electricity";
	e.date = "01-01-2025";
	e.amount = 500.0;

	// Now add them to vector and create new space for next addtion
	expenses.push_back(s);
	expenses.push_back(e);

	// Save the expenses to the file 
	saveExpenseToFile(e);
	saveExpenseToFile(s);
}

// For calculate daily expense
double dailyExpense(const std::string& date)
{
	std::ifstream file("data/expenses.txt");
	if (!file)
	{
		return 0.0;
	}

	double total = 0.0;
	Expense e;

	while (file >> e.date >> e.type >> e.amount)
	{
		if (e.date == date)
			total += e.amount;
	}
	return total;
}

// For calculating monthly expenses
double monthlyExpense(int month, int year)
{
	std::ifstream file("data/expenses.txt");
	if (!file)
	{
		return 0.0;
	}

	double total = 0.0;
	Expense e;

	while (file >> e.date >> e.type >> e.amount)
	{
		int m = std::stoi(e.date.substr(3, 2));
		int y = std::stoi(e.date.substr(6, 4));

		if (m == month && y == year)
			total += e.amount;
	}
	return total;
}

// For calculating yearly expenses
double yearlyExpense(int year)
{
	std::ifstream file("data/expenses.txt");
	if (!file) return 0.0;

	double total = 0.0;
	Expense e;

	while (file >> e.date >> e.type >> e.amount)
	{
		int y = std::stoi(e.date.substr(6, 4));
		if (y == year)
			total += e.amount;
	}
	return total;
}

// For Calculating total expenses
double totalExpense()
{
	std::ifstream file("data/expenses.txt");
	if (!file)
	{
		return 0.0;
	}
	double total = 0.0;
	Expense e;
	while (file >> e.date >> e.type >> e.amount)
	{
		total += e.amount;
	}
	file.close();
	return total;
}

// Function to display the expense menu 
void expensesMenu(std::vector<Expense>& expenses)
{
	std::cout << "===============================\n";
	std::cout << "            Expenses           \n";
	std::cout << "===============================\n";

	int choice;
	std::cout << "1) View daily expenses\n2) View monthly expenses\n3) View yearly expenses\n4) View all time expenses\n5) Back\n";
	std::cin >> choice;

	switch (choice)
	{
	case 1: 
	{
		std::string date;
		std::cout << "Enter date(DD-MM-YYYY): ";
		std::cin >> date;
		if (!validDate(date))
		{
			std::cout << "Invalid date format!\n";
			break;
		}

		std::cout << "Expense for " << date << " is: " << dailyExpense(date) << '\n';
		break;
	}
	case 2: 
	{
		int month;
		int year;

		std::cout << "Enter month: ";
		std::cin >> month;
		std::cout << "Enter year: ";
		std::cin >> year;

		// Check if month and year is valid
		if (month < 0 || month > 12 || year < 2000 || year > 2025)
		{
			std::cout << "Invalid month/year! Try again\n";
			break;
		}

		std::cout << "Expenses: " << monthlyExpense(month, year) << '\n';
		break;
	}
	case 3: 
	{
		int year;
		std::cout << "Enter year: ";
		std::cin >> year;

		// Check if the year is valid
		if (year < 2000 || year > 2025)
		{
			std::cout << "Invalid year! Try again\n";
			break;
		}
		std::cout << "Expenses: " << yearlyExpense(year) << '\n';
		break;
	}
	case 4: 
	{
		std::cout << "Expenses: " << totalExpense() << '\n';
		break;
	}
	case 5:
	{
		return;
	}
	default: 
	{
		std::cout << "Invalid input! Try again\n";
		break;
	}

	}
}

// Function to calculate daily profit
double dailyProfit(const std::string& date)
{
	double profit = dailyRevenue(date) - dailyExpense(date);

	Profit p;
	p.label = "daily";
	p.period = date;
	p.amount = profit;

	saveProfitToFile(p); // Storing the profit in the file
	return profit;
}

// Function to calculate monthly profit 
double monthlyProfit(int month, int year)
{
	double profit = monthlyRevenue(month, year) - monthlyExpense(month, year);

	Profit p;
	p.label = "monthly";
	p.period = std::to_string(month) + "-" + std::to_string(year);
	p.amount = profit;

	saveProfitToFile(p);
	return profit;
}

// Function to calculate yearly profit 
double yearlyProfit(int year)
{
	double profit = yearlyRevenue(year) - yearlyExpense(year);

	Profit p;
	p.label = "yearly";
	p.period = std::to_string(year);
	p.amount = profit;

	saveProfitToFile(p);
	return profit;
}

// Function to calculate all time profit 
double totalProfit()
{
	double profit = allRevenue() - totalExpense();

	Profit p;
	p.label = "total";
	p.period = "all-time";
	p.amount = profit;

	saveProfitToFile(p);
	return profit;
}

// Function to display the profit menu 
void profitMenu(std::vector<Profit>& profits)
{
	std::cout << "===============================\n";
	std::cout << "              Profit            \n";
	std::cout << "===============================\n";

	int choice;
	std::cout << "1) View daily profit\n2) View monthly profit\n3) View yearly profit\n4) View all time profit\n5) Back\n";
	std::cin >> choice;

	switch (choice)
	{
	case 1: 
	{
		std::string date;
		std::cout << "Enter date(DD-MM-YYYY): ";
		std::cin >> date;
		if (!validDate(date))
		{
			std::cout << "Invalid date format!\n";
			break;
		}

		std::cout << "Profit on " << date << " is: " << dailyProfit(date) << '\n';
		break;
	}
	case 2: 
	{
		int month;
		int year;

		std::cout << "Enter month: ";
		std::cin >> month;
		std::cout << "Enter year: ";
		std::cin >> year;

		// Check if month and year is valid
		if (month < 0 || month > 12 || year < 2000 || year > 2025)
		{
			std::cout << "Invalid month/year! Try again\n";
			break;
		}

		std::cout << "Profit: " << monthlyProfit(month, year) << '\n';
		break;
	}
	case 3:
	{
		int year;
		std::cout << "Enter year: ";
		std::cin >> year;

		// Check if the year is valid
		if (year < 2000 || year > 2025)
		{
			std::cout << "Invalid year! Try again\n";
			break;
		}

		std::cout << "Profit: " << yearlyProfit(year) << '\n';
		break;
	}
	case 4:
	{
		std::cout << "Total Profit: " << totalProfit() << '\n';
		break;
	}
	case 5:
	{
		return;
	}
	default:
	{
		std::cout << "Invalid Input! Try again";
		break;
	}

	}

}

