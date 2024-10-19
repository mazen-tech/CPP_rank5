#include <iostream>
#include "../header/MutanStack.hpp"

int main()
{
    MutanStack<int> mstack_test;

    mstack_test.push(5);
    mstack_test.push(17);

    //std::cout << mstack_test.top() << std::endl;
    //mstack_test.pop();
    //std::cout << mstack_test.size() << std::endl;

    std::cout << GREEN << "THE STACK ELEMENTS \n" << RESET;
    mstack_test.push(3);
    mstack_test.push(60);
    mstack_test.push(789);
    mstack_test.push(0);
    
    std::cout << "------------------\n";
    MutanStack<int>::it test1 = mstack_test.begin();
    MutanStack<int>::it test2 = mstack_test.end();
    std::cout << RED << "Begin: " << *test1 << std::endl << RESET;
    std::cout << RED <<"end: " << *test2 << std::endl << RESET;


    while (test1 != test2)
    {
        std::cout << *test1 << std::endl;
        ++test1;
    }

    std::stack<int> s(mstack_test);
}