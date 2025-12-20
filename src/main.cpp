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
	// Declaring a vector for storing information about sale
	std::vector<Sale> sales;
	// Declaring a vector for storing employee's information
	std::vector<Employee> employees =
	{
		{"Alex", "alex123", "emp1", "Fueler"},
		{"Umer", "umer123", "emp2", "Fueler"},
		{"Ali", "ali123", "man1", "Manager"},
		{"Andrew", "andrew123", "own1", "Owner"}
	};
	
	// Declaring a vector for Delivery
	std::vector<Delivery> d;
	//first we take info of adding diliveries
	addDelivery(d);
    //now we show the dilivery success
    showDeliveries(d);
	// Declaring a vector for payment
	std::vector<Payment> p;
	//we give option to the user to add info for payment
    addPayment(p);
    // now we give him a recipet in a formatted way
    showPayments(p);

	// Declaring the revenue variable
	double revenue = 0;
	// Running the program 
	runProgram(employees, pumps, fuels, sales, revenue);
	return 0;
}

// Function defination for running the program
void runProgram(std::vector<Employee>& employees, std::vector<Pump>& pumps, std::vector<Fuel>& fuels,std::vector<Sale>& sales, double& revenue)
{
	int choice;
	Employee loggedUser;
	while (true)
	{
		while (true)
		{
			if (login(loggedUser, employees))
				break;
		}
		//std::cout << "Enter your choice: \n1) Add Pump\n2) Add Fuel\n3) Sell\n4) Exit\n";
	    animateTxt("Enter your choice: \n1) Add Pump\n2) Add Fuel\n3) Sell\n4) Exit\n");
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
			}
			continue;
		case 3: 
			makeSale(sales);
			continue;
		case 4:
			std::cout << "Exiting.....";
			std::this_thread::sleep_for(std::chrono::seconds(1));
			return;
		default:
			std::cout << "Invalid Input!\n";
			continue;
		}
	}
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
	
	// Now check if the pump ID is correct or not 
	for (int i = 0; i < pumps.size(); i++)
	{
		bool pumpFound = false; // Initializing the local variable to false
		
		// Check using if condition
		if (pumId == pumps[i].pumpID)
		{
			pumpFound = true;
			break;
		}

		// If no pump is found then print the invalid message
		if (!pumpFound)
		{
			std::cout << "Invalid pump ID! Try Again";
			return false;
		}
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
	std::cout << "Enter the date: ";
	std::cin >> s.date;
	s.totalAmount = s.price * s.liters;
	sales.push_back(s);  // Stores the sale and creates new storage location in the vector
	
	// Generating the reciept
	std::cout << "===============================================\n";
	std::cout << "                     RECIEPT                   \n";
	std::cout << "===============================================\n";
	std::cout << "Fuel: " << std::setw(3) << s.fuel << '\n';
	std::cout << "Liters Sold: " << std::setw(3) << s.liters << '\n';
	std::cout << "Total price: " << std::setw(3) << s.totalAmount << '\n';
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
    std::cout<<"------------------------\n";
    std::cout<<"  Give Delivery Details \n";
    std::cout<<"------------------------\n";
    std::cout << "Enter fuel type: ";
    std::cin >> d.fuel;
    std::cout << "Enter delivery date: ";
    std::cin >> d.date;
    std::cout << "Enter liters delivered: ";
    std::cin >> d.litersDelivered;
    std::cout << "Enter delivery cost: ";
    std::cin >> d.deliveryCost;
    deliveries.push_back(d);
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
         std::cout<<"\n================\n";
        std::cout<<"Delivery Status\n";
        std::cout<<"================\n";
        std::cout << "Delivery " << i + 1 << '\n';
        std::cout << "Fuel: " << deliveries[i].fuel << '\n';
        std::cout << "Date: " << deliveries[i].date << '\n';
        std::cout << "Liters Delivered: " << deliveries[i].litersDelivered << '\n';
        std::cout << "Cost: " << deliveries[i].deliveryCost << '\n';
    }
}
