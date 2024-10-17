#include "../header/Interpreter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "not correct argumet[ERROR]\n";

    else
    {
        Interpreter test(av[1]);
        std::cout << test << std::endl;
    }
    return (0);
}