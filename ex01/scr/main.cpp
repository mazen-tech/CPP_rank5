#include "../header/RPN.hpp"

int main(int ac, char **av)
{
    RPN test;
    if (ac != 2)
    {
        std::cerr << "Error: " << av[0] << "not right argument" << std::endl;
        return 1;
    }


    try
    {
        test.evaluate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    return (0);
}