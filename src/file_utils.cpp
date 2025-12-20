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

// For Revenue

void saveRevenueToFile(double revenue, const std::string& type, const std::string& identifier)
{
    std::string filename = "data/" + type + "_revenue.txt";
    if (!identifier.empty()) {
        filename = "data/" + type + "_revenue_" + identifier + ".txt";
    }

    std::ofstream file(filename);
    if (!file) return;
    file << revenue;
    file.close();
}

double loadRevenueFromFile(const std::string& type, const std::string& identifier)
{
    std::string filename = "data/" + type + "_revenue.txt";
    if (!identifier.empty()) {
        filename = "data/" + type + "_revenue_" + identifier + ".txt";
    }

    std::ifstream file(filename);
    if (!file) return 0.0;

    double revenue = 0.0;
    file >> revenue;
    file.close();
    return revenue;
}