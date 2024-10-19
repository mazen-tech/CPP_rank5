#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename t>
void iter(t *arr, size_t len, void (*func)(t&))
{
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

#endif