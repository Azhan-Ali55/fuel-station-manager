#include <string>

// Stores the fuel name, price, and quantity
struct Fuel 
{
    std::string name;
    float price;
    float liters;
};

// Stores the information about purchased fuel
struct Sale
{
    std::string fuel;
    std::string date;
    float liters;
    float price;
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
    float litersDelivered;
    float deliveryCost;
};