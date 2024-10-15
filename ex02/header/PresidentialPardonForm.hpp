#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
private:
    const std::string target;

    PresidentialPardonForm(void);
public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    ~PresidentialPardonForm();

    using Form::operator=;
    const std::string &getTarget(void) const;
    void execute(const Bureaucrat &ex) const;
};


#endif