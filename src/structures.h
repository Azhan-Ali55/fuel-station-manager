#pragma once

#include <string>

// Stores information about payment methods
struct Payment
{
    std::string method;
};

// Stores the information about purchased fuel
struct Sale
{
    std::string fuel;
    std::string date;
    int pumpId;
    double liters;
    double price;
    double totalAmount;
    Payment payment;
};

// Stores the information about employees
struct Employee
{
    std::string name;
    std::string username;
    std::string password;
    std::string role;
};

// Stores the information about deliveries
struct Delivery
{
    std::string fuel;
    std::string date;
    double litersDelivered;
    double deliveryCost;
};

// Stores information about the pump
struct Pump
{
    int pumpID;
    std::string fuelType;
    double maxCapacity = 500.0;
    double dispensedLiters;
    double currentLiters;
    bool leak;
    bool malfunc;
};

// Stores information about the expenses
struct Expense 
{
    std::string type;
    std::string date; 
    double amount;
};

// Stores information about profit
struct Profit
{
    std::string label;
    std::string period;  
    double amount;
};

// Stores informaiton about the fuel stock
struct FuelStock
{
    std::string fuelType;
    double currentLiters;
    double maxCapacity;
};