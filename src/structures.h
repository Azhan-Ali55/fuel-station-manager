#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

// Stores the fuel name, price, and quantity
struct Fuel 
{
    std::string name;
    double price;
    double liters;
};

// Stores the information about purchased fuel
struct Sale
{
    std::string fuel;
    std::string date;
    int saleId;
    double liters;
    double price;
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

// Stores information about payment methods
struct Payment
{
    std::string paymentMethod;
    std::string date;
    double amount;
};

// Stores information about the pump
struct Pump
{
    int pumpNum;
    std::string fuelType;
    double dispensedLiters;
};

#endif