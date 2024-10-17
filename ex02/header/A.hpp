#pragma once

#include "Base.hpp"

class A : public Base
{
public:
    A(void);
    A(const A &copy);
    ~A();

    A &operator=(const A&);
};
