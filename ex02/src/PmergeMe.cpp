#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::~PmergeMe() { }

bool PmergeMe::validateInput(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: not valid number of arguments" << std::endl;
        return false;
    }

    for (int i = 1; i < ac; i++) // Start from 1 to skip the program name
    {
        std::string str = av[i];
        if (str.empty() || (str[0] == '0' && str.length() > 1)) // Check for leading zero
        {
            std::cerr << "Error: All input must be positive integers" << std::endl;
            return false;
        }
        for (char c : str) // Check if each char is a digit
        {
            if (!isdigit(c))
            {
                std::cerr << "Error: All input must be positive integers" << std::endl;
                return false;
            }
        }
    }
    return true;
}

std::vector<int> PmergeMe::parseArg(int ac, char **av)
{
    std::vector<int> seq;
    int num;

    for (int i = 1; i < ac; i++) // Start from 1 to skip the program name
    {
        num = std::atoi(av[i]);
        if (num <= 0) // Ensure only positive integers are added
        {
            std::cerr << "Error: All input must be positive integers" << std::endl;
            continue; // Skip invalid numbers
        }
        seq.push_back(num);
    }
    return seq;
}

void PmergeMe::printTime(const std::chrono::high_resolution_clock::time_point &start,
                         const std::chrono::high_resolution_clock::time_point &end,
                         const std::string &containerName)
{
    std::chrono::duration<double, std::milli> time = end - start;
    std::cout << "Time of the process: " << containerName << " : " << time.count() << " ms" << std::endl;
}

// Merge for Vector
static void mergeVector(std::vector<int> &left, std::vector<int> &right, std::vector<int> &seq)
{
    auto itLeft = left.begin();
    auto itRight = right.begin();
    auto itSeq = seq.begin();

    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft <= *itRight)
        {
            *itSeq = *itLeft;
            ++itLeft;
        }
        else
        {
            *itSeq = *itRight;
            ++itRight;
        }
        ++itSeq;
    }

    while (itLeft != left.end())
    {
        *itSeq = *itLeft;
        ++itLeft;
        ++itSeq;
    }

    while (itRight != right.end())
    {
        *itSeq = *itRight;
        ++itRight;
        ++itSeq;
    }
}

static void insertSortVector(std::vector<int> &seq)
{
    int key;
    for (size_t i = 1; i < seq.size(); i++)
    {
        key = seq[i];
        int j = i - 1;
        while (j >= 0 && seq[j] > key)
        {
            seq[j + 1] = seq[j];
            --j;
        }
        seq[j + 1] = key;
    }
}


std::vector<int> PmergeMe::parseArgString(const std::string &input)
{
    std::vector<int> seq;
    std::istringstream iss(input);
    int num;

    while (iss >> num)
    {
        if (num > 0) // Ensure only positive integers are added
        {
            seq.push_back(num);
        }
        else
        {
            std::cerr << "Error: All input must be positive integers" << std::endl;
        }
    }
    return seq;
}


void PmergeMe::mergeInsertSortV(std::vector<int> &seq)
{
    if (seq.size() <= 10)
    {
        insertSortVector(seq);
        return;
    }

    std::vector<int> left(seq.begin(), seq.begin() + seq.size() / 2);
    std::vector<int> right(seq.begin() + seq.size() / 2, seq.end());

    mergeInsertSortV(left);
    mergeInsertSortV(right);
    mergeVector(left, right, seq);
}

/*************************************************************/

// Merge for List
static void mergeList(std::list<int> &left, std::list<int> &right, std::list<int> &seq)
{
    auto itLeft = left.begin();
    auto itRight = right.begin();
    auto itSeq = seq.begin();

    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft <= *itRight)
        {
            *itSeq = *itLeft;
            ++itLeft;
        }
        else
        {
            *itSeq = *itRight;
            ++itRight;
        }
        ++itSeq;
    }

    while (itLeft != left.end())
    {
        *itSeq = *itLeft;
        ++itLeft;
        ++itSeq;
    }

    while (itRight != right.end())
    {
        *itSeq = *itRight;
        ++itRight;
        ++itSeq;
    }
}

static void insertSortList(std::list<int> &seq)
{
    for (auto it = ++seq.begin(); it != seq.end(); ++it)
    {
        auto key = *it;
        auto j = it;
        while (j != seq.begin() && *std::prev(j) > key)
        {
            *j = *std::prev(j);
            --j;
        }
        *j = key;
    }
}

void PmergeMe::mergeInsertSortL(std::list<int> &seq)
{
    if (seq.size() <= 10)
    {
        insertSortList(seq);
        return;
    }

    auto middle = std::next(seq.begin(), seq.size() / 2);
    std::list<int> left(seq.begin(), middle);
    std::list<int> right(middle, seq.end());

    mergeInsertSortL(left);
    mergeInsertSortL(right);
    mergeList(left, right, seq);
}
