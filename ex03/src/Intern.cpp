#include "../header/Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern &copy) { *this = copy; }

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    return (*this);
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    Form *form;

    t_form data[] =
    {
        {"Presidential pardon", new PresidentialPardonForm(target)},
        {"Robotomy request", new RobotomyRequestForm(target)},
        {"Shrubbery creation", new ShrubberyCreationForm(target)},
        {"", NULL}
    };

    form = NULL;
    for (int i = 0; data[i].form != NULL; i++)
    {
        if (data[i].type == formName)
            form = data[i].form;
        else    
            delete data[i].form;
    }

    if (form == NULL)
        std::cout << "Inter can't find the form: " << formName << std::endl;
    else 
        std::cout << "Intern wrote form " << formName << std::endl;
    return (form);
}