#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    typedef struct s_form
    {
        std::string type;
        Form *form;
    } t_form;
public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();

    Intern &operator=(const Intern &copy);
     Form *makeForm(const std::string &formName, const std::string &target) const;

};

#endif 