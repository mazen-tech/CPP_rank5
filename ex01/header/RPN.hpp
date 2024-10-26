#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
private:
    std::stack<int> operands;
public:
    void push(int value);
    void evaluate(const std::string &expression);
    void perform_operation(char op);
    int stringToInt(const std::string& tok);
    int pop();
    bool isNumber(const std::string &s);
};


#endif