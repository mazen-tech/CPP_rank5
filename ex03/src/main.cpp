#include "../header/Intern.hpp"

int main ()
{
    Intern test;
    Form *t;

    t = test.makeForm("Shrubbery creation", "4242");
    std::cout << *t << std::endl;
    std::cout << GREEN << "\n--------------------------------\n" << RESET;
    t = test.makeForm("Robotomy request", "4242");
    std::cout << *t << std::endl;
    std::cout << GREEN << "\n--------------------------------\n" << RESET;
    t = test.makeForm("Presidential pardon", "4242");
    std::cout << *t << std::endl;
 


	return 0;
}