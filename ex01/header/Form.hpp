#pragma once

//#include "Bureaucrat.hpp"
#include "iostream"
#include "string"

/*colors*/
#define RESET   "\033[0m"
#define RED     "\033[31m"      // Red color
#define GREEN   "\033[32m"      // Green color
#define YELLOW  "\033[33m"      // Yellow color
#define BLUE    "\033[34m"      // Blue color

class Bureaucrat;

class Form
{
    private:
        static const int maxGrad = 1;
        static const int minGrad = 150;

        const std::string name;
        const int GradToSign;
        const int GradToExcute;
        bool _Signed;

        Form(void);
    public:
        Form(const std::string &name, int GradToSign, int GradToExcute);
        Form(const Form &copy);
        ~Form();

        Form &operator=(const Form &copy);
        //getters
        const std::string& getName(void) const;
        int getGradToSign(void) const;
        int getGradToExcute(void) const;
        bool isSigned(void) const;
        void BeSigned(const Bureaucrat &b);

    private:
        class GradeTooHighException : public std::exception
        {
        private:
            const char *msg;
        public:
            GradeTooHighException(void); //constructor
            GradeTooHighException(const char *msg); //constructor with para
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
        private:
            const char *msg;
        public:
            GradeTooLowException();
            GradeTooLowException(const char *msg);
            const char *what() const throw();
        };
};


std::ostream &operator<<(std:: ostream &out, Form &b);