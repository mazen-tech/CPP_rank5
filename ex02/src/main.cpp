#include "../header/Bureaucrat.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include <ctime>

int main ()
{
    Bureaucrat		mazen("Mazen", 1);
	Bureaucrat		michal("Michal", 40);
	Bureaucrat		ola("Ola", 150);
	Form			*form = NULL;

	srand(time(NULL));
	std::cout << GREEN << "### execute an unsigned presidential form ###\n" << RESET;
	try
    {
        form = new PresidentialPardonForm("42_warsaw");
        std::cout << YELLOW << mazen <<" Form address number: " << RESET << form << std::endl;
        form->execute(mazen);
        delete form;
        form = NULL;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    std::cout << std::endl;
    std::cout << GREEN << "### execute an signed presidential form ###\n" << RESET;
    try
    {
        form = new PresidentialPardonForm("42_warsaw signed form");
        std::cout << YELLOW << michal <<" Form address number: " << RESET << form << std::endl;
        form->BeSigned(michal);
        form->execute(michal);
        delete form;
        form = NULL;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
	
    std::cout << std::endl;
    std::cout << GREEN << "### sign and execute robotomy request form ###\n" << RESET;
	try
	{
		form = new RobotomyRequestForm("42_warsaw Robot form");
        std::cout << YELLOW << mazen <<" Form address number: " << RESET << form << std::endl;
		mazen.signForm(*form);
        mazen.executeForm(*form);
		std::cout << std::endl;
        std::cout << YELLOW << ola << RESET << std::endl;
		ola.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl;
    std::cout << GREEN << "### sign and execute shrubbery request form ###\n" << RESET;
	try
	{
		form = new ShrubberyCreationForm("truskawki");
        std::cout << YELLOW << mazen <<" Form address number: " << RESET << form << std::endl;
		mazen.signForm(*form);
		mazen.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}