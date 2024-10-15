#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
private:
    const std::string target;
    RobotomyRequestForm();
public:
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
    const std::string &getTarget(void) const;
    virtual void execute(const Bureaucrat &ex) const;
};

#endif