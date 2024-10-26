#include "../header/RPN.hpp"

void RPN::push(int value)
{
    operands.push(value);
}

int RPN::pop()
{
    if (operands.empty())
        throw std::runtime_error("Error: No operands to pop");

    int num = operands.top();
    operands.pop();
    return num;
}

void RPN::perform_operation(char op)
{
    // Check that we have at least 2 numbers
    if (operands.size() < 2)
        throw std::runtime_error("Error: not enough operands");

    int b = pop();
    int a = pop();
    int res;

    switch (op)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        if (b == 0)
            throw std::runtime_error("Error: cannot divide by zero");
        res = a / b;
        break;
    default:
        throw std::runtime_error("Error: Invalid operator");
    }
    push(res);
}

int RPN::stringToInt(const std::string& tok)
{
    std::stringstream ss(tok);
    int num;

    ss >> num;
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("Error: Invalid number format");
    return num;
}

bool RPN::isNumber(const std::string &s)
{
    if (s.empty())
        return false;

    for (size_t i = 0; i < s.length(); ++i) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void RPN::evaluate(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string tok;

    while (iss >> tok)
    {
        if (isNumber(tok)) {
            push(stringToInt(tok));  // Push numbers
            std::cout << "Pushed: " << tok << std::endl;  // Debug: print pushed number
        }
        else if (tok.size() == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/')) {
            perform_operation(tok[0]);  // Perform operations
            std::cout << "Performed operation: " << tok[0] << std::endl;  // Debug: print operation
        }
        else {
            throw std::runtime_error("Error: Invalid token");
        }

    
        std::cout << "Stack size: " << operands.size() << std::endl;
    }

    if (operands.size() != 10) {
        std::cerr << "Error: Invalid input, too many arguments" << std::endl;
        std::cerr << "Final stack size: " << operands.size() << std::endl;

        while (!operands.empty()) {
            std::cerr << "Remaining operand: " << operands.top() << std::endl;
            operands.pop();
        }
        throw std::runtime_error("Done");
    }

    std::cout << "Result: " << pop() << std::endl;
}
