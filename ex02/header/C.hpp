#pragma once

#include "Base.hpp"

class C : public Base
{
public:
    C(void);
    C(const C &copy);
    ~C();

    C &operator=(const C&);
};