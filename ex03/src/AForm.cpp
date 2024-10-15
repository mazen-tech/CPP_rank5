#include "../header/AForm.hpp"
#include "../header/Bureaucrat.hpp"

/*exceptions*/
Form::GradeTooHighException::GradeTooHighException(void)
{
    this->msg = "the grad is so high than the maximum\n";
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg) {}

//const char *what() const throw();
const char *Form::GradeTooHighException::what() const throw()
{
    return (this->msg);
}


/*---------------------------------------------------------*/

Form::GradeTooLowException::GradeTooLowException(void)
{
    this->msg = "the grad is so low than the minimum\n";
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) : msg(msg) {}

//const char *what() const throw();
const char *Form::GradeTooLowException::what() const throw()
{
    return (this->msg);
}

Form::InvalidFormException::InvalidFormException(void)
{
    this->msg = "the form can't be executed";
}

Form::InvalidFormException::InvalidFormException(const char *msg) : msg(msg) 
{}

/*Constructors and destructors of class Form*/
Form::Form() : name(), GradToSign(1), GradToExcute(1), _Signed(false) {}

Form::Form(const std::string &name, int GradToSign, int GradToExcute) : name(name), GradToSign(GradToSign), GradToExcute(GradToExcute)
{
    if (GradToSign < 1 || GradToExcute < 1)
        throw GradeTooHighException();
    else if (GradToSign > 150 || GradToExcute > 150)
        throw GradeTooLowException();
    this->_Signed = false;
}

Form::Form(const Form &copy) : name(copy.name), GradToSign(copy.GradToSign), GradToExcute(copy.GradToExcute), _Signed(copy._Signed) {}

Form::~Form() {}

/*public functions*/
Form& Form::operator=(const Form &copy)
{
    this->_Signed = copy._Signed;
    return (*this);
}

const std::string&Form::getName(void) const
{
    return (this->name);
}

int Form::getGradToSign(void) const
{
    return (this->GradToSign);
}

int Form::getGradToExcute(void) const
{
    return (this->GradToExcute);
}

bool Form::isSigned(void) const
{
    return (this->_Signed);
}

void Form::BeSigned(const Bureaucrat &b)
{
    if(b.getGrad() > this->GradToSign)
        throw GradeTooLowException("Bureacrat is not allowed to get signed");
    this->_Signed = true;
}

/* ##that's how the output will look like##

Form: Text Form Signed: true
GradTosign: 5
GradeToEcute: 10
*/
std::ostream &operator<<(std:: ostream &out, Form &b)
{
    out << "Form: " << b.getName() << " Signed: " << (b.isSigned() ? "true" : "false");
    out << "GradTosign: " << b.getGradToSign();
    out << "GradeToEcute: " << b.getGradToExcute();

    return (out);
}


//ex02
const char *Form::InvalidFormException::what() const throw() {
    return this->msg;
}

void Form::checkExecutability(const Bureaucrat &ex) const
{
    if (ex.getGrad() > GradToExcute)
        throw GradeTooLowException("Bureauctar can't be executer (to low)");
    if (!this->_Signed)
        throw InvalidFormException("Not signed form :( ");
}


Form::InvalidFormException::~InvalidFormException() throw() {}