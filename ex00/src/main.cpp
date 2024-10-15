#include "../header/Bureaucrat.hpp"

int main()
{
    Bureaucrat b1("mazen", 1);
    Bureaucrat b2("john", 150);
    Bureaucrat b3("alex", 50);

    std::cout << "test creating bureaucrat opjects\n";
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << b3 << std::endl;

    //testing gradTooHigh and TooLow
    std::cout << "----------------TEST OF TooHigh----------------\n";
    try
    {
        Bureaucrat test("test", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << "cannot creat test" << std::endl;
        std::cout << "Exception:" << e.what() << '\n';
    }

    std::cout << "----------------TEST OF TooLow----------------\n";
    try
    {
        Bureaucrat test1("test1", 160);
    }
    catch(const std::exception& e)
    {
        std::cout << "cannot creat test1" << std::endl;
        std::cout << "Exception:" << e.what() << '\n';
    }

    std::cout << "----------------TEST OF Increament----------------\n";
    try
    {
        b1.incrementGrad();
    }
    catch(const std::exception& e)
    {
        std::cout << "Cannot increment the grade of b1" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "----------------TEST OF Derement----------------\n";
    try
    {
        b2.decrementGrad();
    }
    catch(const std::exception& e)
    {
        std::cout << "Cannot increment the grade of b2" << std::endl;
		std::cout << "Exception: " << e.what() << std::endl;
    }

    
    
    return (0);
}