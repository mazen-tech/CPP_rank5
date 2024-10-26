#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <vector>
#include <chrono>

class PmergeMe
{
public:
    PmergeMe(); // Constructor
    ~PmergeMe(); // Destructor
    bool validateInput(int ac, char **av);
    std::vector<int> parseArg(int ac, char **av);

    template <typename T>
    void printUnsortedSeq(const T &seq);
    
    template <typename T>
    void printSortedSeq(const T &seq);

    std::vector<int> parseArgString(const std::string &input);
    void mergeInsertSortV(std::vector<int> &seq);
    void mergeInsertSortL(std::list<int> &seq);
    void printTime(const std::chrono::high_resolution_clock::time_point &start,
                   const std::chrono::high_resolution_clock::time_point &end,
                   const std::string &containerName);
};

template <typename T>
void PmergeMe::printUnsortedSeq(const T &seq)
{
    std::cout << "Before sorting:\n";
    for (typename T::const_iterator it = seq.begin(); it != seq.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void PmergeMe::printSortedSeq(const T &seq)
{
    std::cout << "After sorting:\n";
    for (typename T::const_iterator it = seq.begin(); it != seq.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif
