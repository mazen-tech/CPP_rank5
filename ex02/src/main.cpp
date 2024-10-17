#include "../header/A.hpp"
#include "../header/B.hpp"
#include "../header/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
    int r;

    r = rand() % 3; //to keep the rang in three
    if (r == 0)
        return (new B);
    if (r == 1)
        return (new A);
    if (r == 2)
        return (new C);

    else 
        return (NULL);
}


void identify(Base *p)
{
    if (dynamic_cast<A*>(p))//if P pointing to A print A etc ....
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base &p)
{
    Base ptr;
    try
    {
        ptr = dynamic_cast<A&>(p);
        std::cout << "A\n";
    }
    catch(const std::exception& e){ }
    
    try
    {
        ptr = dynamic_cast<B&>(p);
        std::cout << "B\n";
    }
    catch(const std::exception& e){ }

    try
    {
        ptr = dynamic_cast<C&>(p);
        std::cout << "C\n";
    }
    catch(const std::exception& e){ }
}


int main ()
{
    Base *test;
    
    test = generate();
    identify(test);
    delete test;

    test = generate();
    identify(test);
    delete test;

    test = generate();
    identify(test);
    delete test;

    test = generate();
    identify(test);
    delete test;

    test = generate();
    identify(test);
    delete test;

    test = generate();
    identify(test);
    delete test;

    std::cout << "Identify with refrence\n";
    test = generate();
    identify(*test);
    delete test;

    test = generate();
    identify(*test);
    delete test;

    test = generate();
    identify(*test);
    delete test;

    test = generate();
    identify(*test);
    delete test;

    test = generate();
    identify(*test);
    delete test;

    test = generate();
    identify(*test);
    delete test;



}