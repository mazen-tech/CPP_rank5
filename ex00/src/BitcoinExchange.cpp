#include "../header/BitcoinExchange.hpp"

/*
private:
    std::map<std::string, double> btcData;


public:
    BitcoinExchange(const std::string &csvFile); //constructor to read the DBfile
    void readDB(const std::string &dbFile);

    void processInput(const std::string &inputFile); //process the inputfile

private:
    std::string trim(const std::string &str);
    bool isValidDate(const std::string &date);
    bool isValidValue(double value);
    double findClosestPrice(const std::string &date);
*/

BitcoinExchange::BitcoinExchange()
{
    readDB();
}

void BitcoinExchange::readDB()
{
    std::string dbFile = "data.csv"; //as the module have to take only the (input file) as an argrument to we have to difne the DB file inside the code 
    std::ifstream file(dbFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "the Data base file cannot be opened \n";
        return;
    }

    std::string line;
    std::string date;
    double price;
    while (getline(file, line))
    {
        std::stringstream ss(line);
        if (getline(ss, date, ',') && (ss >> price))
            btcData[date] = price;
        else 
            std::cerr << "Error: bad date format from data base file\n";
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &inputFile)
{
    std::string line;
    std::string date;
    double price;
    double value;
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cerr << "the input file cannot be opened \n";
        return;
    }

    while (getline(file, line))
    {
        std::stringstream ss(line);
        if (getline(ss, date, '|') && (ss >> value))
        {
            date = trim(date);
            if (isValidDate(date) && isValidValue(value))
            {
                price = findClosestPrice(date);
                if (price != -1)
                    std::cout << date << " => " << value << " = " << value * price << std::endl;
                else 
                    std::cerr << RED << "Error: no date for date => " << RESET << date << std::endl;
            }

            else 
                std::cerr << RED << "Error: invalid input form or rang \n" << RESET;
        }

        else 
            std::cerr << RED << "Error: bad input format\n" << RESET;
    }
    file.close();
}

/*trailling and removeing the spaces and then returning the trimmed substring*/
std::string BitcoinExchange::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" ");//to find the first_non_space char
    size_t last = str.find_last_not_of(" ");//to find the last_non_space char
    return str.substr(first, last - first + 1);        
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(double value)
{
    if (value < 0 || value > 1000)
        return false;
    return true;
}

double BitcoinExchange::findClosestPrice(const std::string &date)
{
    double closestPrice = -1;
    std::map<std::string, double>::iterator it;

    for (it = btcData.begin(); it != btcData.end(); it++)//we will loop until reach the end of the file
    {
        if (it->first <= date)//it->first (date) & it->second (price)
            closestPrice = it->second;
        else 
            break;
    }
    return closestPrice;
}