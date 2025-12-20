#include "file_utils.h"
#include "fuel_manager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <iomanip>

// Function defination for running the program
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Fuel>& fuels, std::vector<Sale>& sales, std::vector<Delivery>& deliveries, std::vector<Expense>& expenses, std::vector<Profit>& profits)
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
			std::cout << "Enter your choice: \n1) Add Pump\n2) Add Fuel\n3) Sell\n4) Order Fuel\n5) Revenue Report\n6) Expense Report\n7) Profit Report\n8) Log out\n9) Exit\n";
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
				if (addFuel(fuels, pumps))
				{
					std::this_thread::sleep_for(std::chrono::seconds(3));
					std::cout << "The fuel was added succesfully!\n";
				}
				continue;
			}
			case 3:
			{
				makeSale(sales);
				continue;
			}
			case 4:
			{
				addDelivery(deliveries);
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
				loggedIn = false;
				loggedUser = Employee{};
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "Logged out successfully!\n";
				continue;
			}
			case 9:
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
			std::cout << "Enter your choice : \n1) Add Pump\n2) Add Fuel\n3) Sell\n4) Order Fuel\n5) Log out\n6) Revenue Report\n7) Exit\n";
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
				if (addFuel(fuels, pumps))
				{
					std::this_thread::sleep_for(std::chrono::seconds(3));
					std::cout << "The fuel was added succesfully!\n";
				}
				continue;
			}
			case 3:
			{
				makeSale(sales);
				continue;
			}
			case 4:
			{
				addDelivery(deliveries);
				continue;
			}
			case 5:
			{
				loggedIn = false;
				loggedUser = Employee{};
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "Logged out successfully!\n";
				continue;
			}
			case 6: 
			{
				revenueMenu(sales);
				continue;
			}
			case 7:
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
			std::cout << "Enter your choice:\n1) Add Fuel\n2) Sell\n3) Log out\n4) Exit\n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				if (addFuel(fuels, pumps))
				{
					std::this_thread::sleep_for(std::chrono::seconds(3));
					std::cout << "The fuel was added succesfully!\n";
				}
				continue;
			}
			case 2:
			{
				makeSale(sales);
				continue;
			}
			case 3:
			{
				loggedIn = false;
				loggedUser = Employee{};
				std::this_thread::sleep_for(std::chrono::seconds(2));
				std::cout << "Logged out successfully!\n";
				continue;
			}
			case 4:
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
	std::cout << "Enter the fuel type of the pump: ";
	std::cin >> p.fuelType;
	std::cin.ignore(); // Clear the input buffer
	pumps.push_back(p); // Adds a new pump to the vector 
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

	// Asking the user for which pump they want to add the fuel to 
	int pumId;
	std::cout << "Enter the ID of the pump: ";
	std::cin >> pumId;

	bool pumpFound = false; // Initializing the local variable to false

	// Now check if the pump ID is correct or not 
	for (int i = 0; i < pumps.size(); i++)
	{
		// Check using if condition
		if (pumId == pumps[i].pumpID)
		{
			pumpFound = true;
			break;
		}
	}

	// If no pump is found then print the invalid message
	if (!pumpFound)
	{
		std::cout << "Invalid pump ID! Try Again\n";
		return false;
	}

	Fuel f; // Creating the object of the Fuel strcut
	std::cout << "Enter fuel name: ";
	std::cin >> f.name;
	std::cout << "Enter fuel price per liter: ";
	std::cin >> f.price;
	std::cout << "Enter the amount of liters: ";
	std::cin >> f.liters;
	std::cin.ignore(); // Clear the input buffer
	fuels.push_back(f); // Adds a new fuel to the vector 
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
void makeSale(std::vector<Sale>& sales)
{
	Sale s; // Making object for Sale struct 
	std::cout << "Enter the fuel: ";
	std::cin >> s.fuel;
	std::cout << "Enter the liters: ";
	std::cin >> s.liters;
	std::cout << "Enter the price per liter: ";
	std::cin >> s.price;
	
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

	s.totalAmount = s.price * s.liters;

	// Handling payment method
	std::cout << "Enter payment method(Cash/Card/Online): ";
	std::cin >> s.payment.method;

	sales.push_back(s);  // Stores the sale and creates new storage location in the vector
	saveSaleToFile(s);   // Calling function to save the sale

	// Generating the reciept
	std::cout << "===============================================\n";
	std::cout << "                     RECIEPT                   \n";
	std::cout << "===============================================\n";
	std::cout << "Fuel: " << std::setw(3) << s.fuel << '\n';
	std::cout << "Liters Sold: " << std::setw(3) << s.liters << '\n';
	std::cout << "Total price: " << std::setw(3) << s.totalAmount << '\n';
	std::cout << "Paid by: " << std::setw(3) << s.payment.method << '\n';
	std::cout << "Date: " << s.date << '\n';
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
void addDelivery(std::vector<Delivery>& deliveries)
{
	Delivery d;
	std::cout << "------------------------\n";
	std::cout << "  Give Delivery Details \n";
	std::cout << "------------------------\n";
	std::cout << "Enter fuel type: ";
	std::cin >> d.fuel;
	std::cout << "Enter delivery date: ";
	std::cin >> d.date;
	std::cout << "Enter liters: ";
	std::cin >> d.litersDelivered;
	std::cout << "Enter delivery cost: ";
	std::cin >> d.deliveryCost;
	deliveries.push_back(d);

	// Saving delivery to file
	saveDeliveryToFile(d);
	std::cout << "Delivery added successfully!\n";
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

	// For delivery cost
	d.type = "Delivery";
	d.date = "01-01-2025";
	d.amount = 300.0;

	// Now add them to vector and create new space for next addtion
	expenses.push_back(s);
	expenses.push_back(e);
	expenses.push_back(d);

	// Save the expenses to the file 
	saveExpenseToFile(e);
	saveExpenseToFile(s);
	saveExpenseToFile(d);
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

