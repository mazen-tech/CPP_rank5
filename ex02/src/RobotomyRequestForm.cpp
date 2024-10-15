#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : Form("RobotomyRequestForm", 72, 45), target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
    : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : Form("RobotomyRequestForm", 72, 45), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget(void) const 
{
    return (this->target);
}

void RobotomyRequestForm::execute(const Bureaucrat &ex) const
{
    this->checkExecutability(ex);
    if (rand() % 2)
    {
        std::cout << "the Victi... " << this->target;
        std::cout << " has been successfully robotomized " << std::endl;
    }

    else 
        std::cout << "the robotomization on " << this->target << " failed" << std::endl;
}