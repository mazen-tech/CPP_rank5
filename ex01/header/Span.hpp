#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iterator>
#include <vector>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

class Span
{
    private:
        std::vector<int> stor;
        unsigned int N;
    public:
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

        template <typename t>
        void addN(t begin, t end)
        {
            while (begin != end)
            {
                this->addN(*begin);
                begin++;
            }
        }
};
/*overload operaror <<*/
std::ostream &operator<<(std::ostream &out, const Span &p);
#endif