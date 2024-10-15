#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
    const std::string target;

    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    using Form::operator=;
    const std::string &getTarget(void) const;
    void execute(const Bureaucrat &ex) const;
};


#endif