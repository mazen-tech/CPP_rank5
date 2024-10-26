#include "../header/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    
    if (ac != 2)
    {
        std::cout << RED << "Invalid number of arguments ./btc [InputFile.txt]\n" << RESET;
        return 1;
    }

    std::cout << GREEN << "#########################\n";
    std::cout << GREEN << "#                       #\n";
    std::cout << GREEN << "#   BIT COIN EXCHANGE   #\n";
    std::cout << GREEN << "#                       #\n";
    std::cout << GREEN << "#########################\n" << RESET;
    std::cout << std::endl;
    BitcoinExchange test;
    test.processInput(av[1]);


    /*
    //######## Example on ss() functionality and how we can use it diffrently ##########//
    std::stringstream ss(av[1]);
    std::string first_name;
    std::string second_name;
    std::string date_birth;
    double salary;

    if (getline(ss, first_name, ' '))
    {
        ss >> second_name;
        ss >> date_birth;
        ss >> salary;

        if (ss.fail())
        {
            std::cerr << "ss failed" << std::endl;
            return 1;
        }
    }

    std::cout << "first name: " << first_name << std::endl;
    std::cout << "second name: " << second_name << std::endl;
    std::cout << "date of birth: " << date_birth << std::endl;
    std::cout << "salary: " << salary << std::endl;
    */
}