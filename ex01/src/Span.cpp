#include "../header/Span.hpp"

/*
Span(void);
~Span();
Span(unsigned int N);
Span(const Span &copy);

int size(void) const;
int capacity(void) const;
int s_short(void) const;
int s_long(void) const;
void addN(int n);
Span &operator=(const Span &copy);
*/

Span::Span(void) : N(0) /*here N(0) so when no arguments is passed during the creation of span the object will have 0 storage*/
{
    this->stor.reserve(0);
}

Span::Span(unsigned int N) : N(N) /*constructor with parameter when the const is calles the object will be created with sporage capacity = N*/
{
    this->stor.reserve(N);
}

Span::~Span()
{
    std::cout << RED << "The span destructor has been called\n";
}

Span::Span(const Span &copy)
{
    *this = copy;
}

int Span::size(void) const
{
    return (this->stor.size());
}

int Span::capacity(void) const
{
    return (this->N);
}

void Span::addN(int n)
{
    if (this->stor.size() == N) //if size = capacity that's means there is not more place to store
        throw std::overflow_error("Span is Full");
    this->stor.push_back(n);//other wise we can push more elements inside Span
}

//the simple idea that we are sorting the stack from and thin suptracting start-end
int Span::s_short(void) const
{
    std::vector<int> tmp;

    tmp = stor;
    if (stor.size() < 2)
        throw std::logic_error("not enough numbers stored to provide");
    std::sort(tmp.begin(), tmp.end());
    return (tmp[1] - tmp[0]);//shoetest span difference
}

int Span::s_long(void) const
{
    std::vector<int> tmp;

    tmp = stor;
    if (stor.size() < 2)
        throw std::logic_error("not enough numbers stored to provide");
    std::sort(tmp.begin(), tmp.end());
    return (tmp.back() - tmp.front());//longest span difference
}

Span &Span::operator=(const Span &copy)
{
    this->N = copy.N;
    this->stor = copy.stor;
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Span &p)
{
    out << "Span size: \n" << p.capacity();
    out << "Span elements are: \n" << p.size();
    out << GREEN << "Shortest span: \n" << p.s_short() << RESET;
    out << GREEN << "Longest span: \n" << p.s_long() << RESET;
    return (out); 
}