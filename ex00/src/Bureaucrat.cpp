#include "../header/Bureaucrat.hpp"

/*classes structer*/
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is higher than the maximum");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grad is lower than the maximum");
}

/*public*/
Bureaucrat::Bureaucrat(const std::string& name, int grad) : name(name)
{
    if (grad < 1)
        throw GradeTooHighException();/*throw triggers an exception stopping normal program execution*/
    else if (grad > 150)
        throw GradeTooLowException();
    this->grad = grad;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grad(copy.grad) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    this->grad = copy.grad;
    return (*this);
}

/*getters*/
const std::string& Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrad(void) const
{
    return (this->grad);
}

//increament and decrement function

void Bureaucrat::incrementGrad(void)
{
    if (this->grad == Bureaucrat::maxGrad)
        throw GradeTooHighException();
    this->grad--;
}

void Bureaucrat::decrementGrad(void)
{
    if (this->grad == Bureaucrat::minGrad)
        throw GradeTooLowException();
    this->grad++;
}

/*assignation operator*/
/*finctionality of ostream that is customizes the class onjects are displayed
when output to steams alloweing formatted printing*/
std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrad();
    return (out);
}
