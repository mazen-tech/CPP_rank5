#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        static const int maxGrad = 1;//constant to set the highest
        static const int minGrad = 150;//constant to set the lowed
        const std::string name;
        int grad;

        Bureaucrat(void);//constructor
    
    public:
        Bureaucrat(const std::string& name, int grad);//constructor that takes two ags name and grad
        Bureaucrat(const Bureaucrat& copy);//copy constructor
        ~Bureaucrat(void);//distructor
        Bureaucrat &operator=(const Bureaucrat &copy);

        const std::string &getName(void) const;
        int getGrad(void) const;
        void incrementGrad(void);
        void decrementGrad(void);
        

    private: //class -> exception handling (nested private classes) inherits from standerd library
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
                /*const char* what() const throw is a method
                returning a constant string, doesn't modify
                object state (const), and guarantees no exceptions
                are thrown (throw, deprecated, replaced by noexcept)*/
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
    
};


std::ostream& operator<<(std::ostream& out, Bureaucrat& b);
