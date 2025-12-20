#include "file_utils.h"

// Function Definations

void ensureDataFiles()
{
    std::filesystem::create_directory("data");  // Creates a folder data if it doesnt exist
    std::ofstream("data/sales.txt", std::ios::app);  // creates a file sales.txt inside the data folder
}

// For Sales

void saveSaleToFile(const Sale& s)
{
    std::ofstream file("data/sales.txt", std::ios::app);
    
    if (!file) 
        return;
   
    file << s.date << " " << s.fuel << " " << s.liters << " " << s.price << " " << s.totalAmount << " " << s.payment.method << "\n";
    file.close();
}

void loadSalesFromFile(std::vector<Sale>& sales)
{
    std::ifstream file("data/sales.txt");
    if (!file) 
        return;
    Sale s;
    while (file >> s.date >> s.fuel >> s.liters >> s.price >> s.totalAmount >> s.payment.method)
    {
        sales.push_back(s);
    }
    file.close();
}