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

