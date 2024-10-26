#ifndef BTC_HPP
#define BTC_HPP

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET "\033[0m"

#include <iostream>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

class BitcoinExchange
{
//one private variable difining the line construction of the DB file
private:
    std::map<std::string, double> btcData;


public:
    BitcoinExchange();
    void readDB();

    void processInput(const std::string &inputFile); //process the inputfile

private:
    std::string trim(const std::string &str);
    bool isValidDate(const std::string &date);
    bool isValidValue(double value);
    double findClosestPrice(const std::string &date);
};



#endif