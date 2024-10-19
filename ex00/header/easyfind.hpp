#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>
# include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

/*An iterator is like a generalized pointer that allows you to travers
the element of the container */

template <typename t>
typename t::iterator easyfind(t &container, int val)
{
    return (std::find(container.begin(), container.end(), val));
}

#endif
