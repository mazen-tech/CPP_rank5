#include "../header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : Form ("ShrubberyCreationForm", 145, 137), target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form ("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : Form ("ShrubberyCreationForm", 145, 137), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &ex) const
{
    std::ofstream file;
    std::string name;

    this->checkExecutability(ex);
    name = target + ".shrubbery";
    file.open(name.c_str(), std::ofstream::out);

    file << "      # #### ####               " << std::endl;
    file << "     ### \\/#|### |/####        " << std::endl;
    file << "    ##\\/#/ \\||/##/_/##/_#     " << std::endl;
    file << "  ###  \\/###|/ \\/ # #####     " << std::endl;
    file << " ##_\\_#\\_\\## | #/###_/_####  " << std::endl;
    file << "## #### # \\ #| /  #### ##/##   " << std::endl;
    file << " __#_--###`  |{,###---###-~     " << std::endl;
    file << "          \\ }{                 " << std::endl;
    file << "           }}{                  " << std::endl;
    file << "           }}{                  " << std::endl;
    file << "           {{}                  " << std::endl;
    file << "     , -=-~{ .-^- _             " << std::endl;
    file << "           `}                   " << std::endl;
    file << "            {                   " << std::endl;
	file.close();
}