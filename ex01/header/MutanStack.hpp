#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#include <stack>

template<typename t>
class MutanStack : public std::stack<t>
{
public:
    typedef typename std::stack<t>::container_type::iterator it;
    it begin() { return this->c.begin(); };
    it end() { return this->c.end(); };
};



#endif