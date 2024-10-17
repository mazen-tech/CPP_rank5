#pragma once

#include "Base.hpp"

class B : public Base
{
public:
    B(void);
    B(const B &copy);
    ~B();

    B &operator=(const B&);
};