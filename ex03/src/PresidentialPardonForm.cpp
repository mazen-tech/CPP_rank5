#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : Form("PresentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("PresentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : Form("PresentialPardonForm", 25, 5), target(copy.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget(void) const
{
    return (this->target);
}

void PresidentialPardonForm::execute(const Bureaucrat &ex) const
{
    this->checkExecutability(ex);
    std::cout << this->target << "has been pardoned by Zafod Beeblebrox\n";
}