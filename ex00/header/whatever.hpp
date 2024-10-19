#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename t>
void swap(t &a, t &b)
{
    t tmp;

    tmp = a;
    a = b;
    b = tmp;
}


template<typename t>
const t &min(t &a, t &b)
{
    return (a < b ? a : b);
}

template<typename t>
const t &max(t &a, t &b)
{
    return (a > b ? a : b);
}

#endif