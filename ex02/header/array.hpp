#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename t>//we can use any templete parameter doesn't matter
class array
{
    private:
        t *data;
        int size;
    public:
        array(void);
        ~array(void);
        array(const array &copy);
        array(unsigned int n); //constructor with parameter 

        array &operator=(const array &copy);
        t &operator[](int idx) const;
        int Size(void) const;

};


template<typename t>
array<t>::array(void) : data(NULL), size(0) {}

template<typename t>
array<t>::~array(void) { delete[] this->data; }

template<typename t>
array<t>::array(unsigned int n) : data(new t[n]), size(n) {}

template<typename t>
array<t>::array(const array &copy) : size(copy.size)
{
    //for (int i = 0; i < copy.size; i++)
       // this->data[i] = copy.data[i];
    if (size > 0)
    {
        this->data = new t[size];
        for (int i = 0; i < size; i++)
            this->data[i] = copy.data[i];
    }
    else 
        this->data = NULL;
}

template<typename t>
array<t> &array<t>::operator=(const array &copy)
{
    if (this == &copy)
        return (*this);

    if (this->size > 0)//to check if the array has allocated the mem needed but this line is not necessary
        delete[] this->data;

    this->size = copy.size;
    this->data = new t[size];

    for (int i = 0; i < size; i++)
        this->data[i] = copy.data[i];
    return (*this);
}

/*
#idx is index of element in the array
#simply we are siting the overload operator [] searching for bounds(valid range) and
throws an error if out of range
*/
template<typename t>
t &array<t>::operator[](int idx) const
{
    if (idx < 0 || idx >= size)
        throw std::overflow_error("Index out of bounds");
    return (this->data[idx]);
}

template<typename t>
int array<t>::Size(void) const { return this->size; }

/*overload operator << */
template<typename t>
std::ostream &operator<<(std::ostream &out, const array<t> &array)
{
    out << "Array = { ";
    for (int i = 0; i < array.Size(); i++)
    {
        out << array[i];
        if (i != array.Size() - 1)
            out << ", ";
    }
    out << " }";
    return (out);
}

#endif