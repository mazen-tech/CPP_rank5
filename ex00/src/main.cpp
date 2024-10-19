#include <vector>
#include <deque>
#include <list>
#include <set>
#include <iostream>
#include "../header/easyfind.hpp"

int main ()
{
    std::set<int> test_set;
    std::deque<int> test_deque;
    std::list<int> test_list;
    std::vector<int> test_vector;

    for (int i = 0; i < 5; i++)
    {
        test_set.insert(i);
        test_deque.push_front(i);
        test_list.push_back(i);
    }

    for (int i = 5; i < 11; i++)
        test_vector.push_back(i);

    /*testing with set*/
    std::cout << GREEN << "##TESTING EASYFIND WITH SET##\n" << RESET;
    for(std::set<int>::iterator it = test_set.begin();  it != test_set.end(); it++)
    {
        std::cout << "{" ;
        std::cout << ' ' << *it;
        std::cout << " }";
    }
    std::set<int>::iterator set_it = easyfind(test_set, 0);
    std::cout << "\nFound: " << *set_it << " followed by " << *(++set_it) << std::endl;

    std::set<int>::iterator set_it02 = easyfind(test_set, 2);
    std::cout << "\nFound: " << *set_it02 << " followe by " << *(++set_it02) << " and proceded by " << *(----set_it02) << std::endl; 


    std::cout << GREEN << "##TESTING EASYFIND WITH VECTOR##\n" << RESET;
    for (std::vector<int>::iterator it = test_vector.begin(); it != test_vector.end(); it++)
    {
        std::cout << "{" ;
        std::cout << ' ' << *it;
        std::cout << " }";
    }
    
    std::vector<int>::iterator vector_it = easyfind(test_vector, 7);
    std::cout << "\nFound: " << *vector_it << " followed by " << *(++vector_it) << std::endl;

    std::vector<int>::iterator vector_it02 = easyfind(test_vector, 9);
    std::cout << "\nFound: " << *vector_it02 << " followed by " << *(++vector_it02) << " and proceded by " << *(----vector_it02) << std::endl;

}
