#include <iostream>
#include "../header/Span.hpp"

int main()
{
    Span test(6);
    int num;

    std::cout << GREEN << "Pushing elements inside Span\n" << RESET;
    for (int i = 5; i < 11; i++)
    {
        num = rand() % 50;
        std::cout << "Pushing: " << num << std::endl;
        test.addN(num);
    }

    //testing the stage overflow
    std::cout << std::endl;
    std::cout << "####STORAGE TEST####" <<std::endl;
    try
    {
        test.addN(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << GREEN << "Shortest span: " << RESET << test.s_short() << std::endl;
    std::cout << GREEN << "Longest span: "  << RESET << test.s_long() << std::endl;
}