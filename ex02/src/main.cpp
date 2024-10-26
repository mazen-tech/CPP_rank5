#include "../header/PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <sstream>

/*int main(int argc, char **argv)
{
    PmergeMe test;

    // Validate input arguments
    if (!test.validateInput(argc, argv))
        return 1;
    std::vector<int> unsorted = test.parseArg(argc, argv);
    // Print unsorted sequence
    test.printUnsortedSeq(unsorted);

    // Measure the time needed for sorting and print after sorting 
    auto start = std::chrono::high_resolution_clock::now();
    test.mergeInsertSortV(unsorted);
    auto end = std::chrono::high_resolution_clock::now();
    test.printSortedSeq(unsorted);
    test.printTime(start, end, "vector");

    return 0;
}*/


#include "../header/PmergeMe.hpp"
#include <sstream>

int main(int argc, char **argv)
{
    PmergeMe test;

    if (argc < 2)
    {
        std::cerr << "Error: not valid number of arguments" << std::endl;
        return 1;
    }

    std::string input;
    for (int i = 1; i < argc; ++i)
    {
        input += argv[i];
        if (i < argc - 1) input += " ";
    }
    std::vector<int> unsorted = test.parseArgString(input);

    test.printUnsortedSeq(unsorted);
    test.mergeInsertSortV(unsorted);
    test.printSortedSeq(unsorted);

    return 0;
}

