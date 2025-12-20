#include "file_utils.h"

// Function Definations

void ensureDataFiles()
{
    std::filesystem::create_directory("data");  // Creates a folder data if it doesnt exist
    std::ofstream("data/sales.txt", std::ios::app);  // Creates a file sales.txt inside the data folder if it does not exist
    std::ofstream("data/deliveries.txt", std::ios::app); // Creates a file deliveries.txt inside the data folder if it does not exist 
    std::ofstream("data/expenses.txt", std::ios::app); // Creates a file expenses.txt inside the data folder if it does not exist
    std::ofstream("data/profit_reports.txt", std::ios::app); // Creates a file profit_reports.txt inside the data folder if it does not exist
}

// For Sales

void saveSaleToFile(const Sale& s)
{
    std::ofstream file("data/sales.txt", std::ios::app);
    
    if (!file) 
        return;
   
    file << s.date << " " << s.fuel << " " << s.liters << " " << s.price << " " << s.totalAmount << " " << s.payment.method << '\n';
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

// For deliveries

void saveDeliveryToFile(const Delivery& d)
{
    std::ofstream file("data/deliveries.txt", std::ios::app);

    if (!file)
        return;

    file << d.date << " " << d.fuel << " " << d.litersDelivered << " " << d.deliveryCost << '\n';
    file.close();
}

void loadDeliveriesFromFile(std::vector<Delivery>& deliveries)
{
    std::ifstream file("data/deliveries.txt");

    if (!file)
        return;

    Delivery d;

    while (file >> d.date >> d.fuel >> d.litersDelivered >> d.deliveryCost)
    {
        deliveries.push_back(d);
    }
    
    file.close();
}

// For Expenses

void saveExpenseToFile(const Expense& e)
{
    std::ofstream file("data/expenses.txt", std::ios::app);
    if (!file)
    {
        return;
    }
    file << e.date << " " << e.type << " " << e.amount << '\n';
    file.close();
}

void loadExpensesFromFile(std::vector<Expense>& expenses)
{
    std::ifstream file("data/expenses.txt");
    if (!file)
    {
        return;
    }

    Expense e;
    while (file >> e.date >> e.type >> e.amount)
    {
        expenses.push_back(e);
    }
    file.close();
}

// For Profit 

void saveProfitToFile(const Profit& p)
{
    std::ofstream file("data/profit_reports.txt", std::ios::app);

    if (!file)
    {
        return;
    }

    file << p.period << " " << p.label << " " << p.amount << '\n';

}

void loadProfitFromFile(std::vector<Profit>& reports)
{
    std::ifstream file("data/profit_reports.txt");
    if (!file)
    {
        return;
    }
    Profit p;
    while (file >> p.period >> p.label >> p.amount)
    {
        reports.push_back(p);
    }
    file.close();
}
