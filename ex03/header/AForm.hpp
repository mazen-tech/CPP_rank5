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
        virtual ~Form();

        Form &operator=(const Form &copy);
        //getters
        const std::string& getName(void) const;
        int getGradToSign(void) const;
        int getGradToExcute(void) const;
        bool isSigned(void) const;
        void BeSigned(const Bureaucrat &b);

        /*ex02*/
        virtual void execute(const Bureaucrat &ex) const = 0;

    protected:
        void checkExecutability(const Bureaucrat &ex) const; /*ex02*/

/***************************Nested classes***************************/
    public:
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

        class InvalidFormException : public std::exception /*ex02*/
        {
            private:
                const char *msg;
            public:
                InvalidFormException(void);
                InvalidFormException(const char *msg);
                virtual ~InvalidFormException() throw();

                const char *what() const throw();
        };
};


std::ostream &operator<<(std:: ostream &out, Form &b);