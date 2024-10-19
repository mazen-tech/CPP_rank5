#include "../header/iter.hpp"
#include <iostream>
#include <cstdlib>

template<typename t>
void display(t &element)
{
	std::cout << "The element's vlaue is: " << element << std::endl;
}

void setRandomValue(int &number)
{
	number = rand() % 100;
}

int main()
{
	int test[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "Display the array elements\n";
	iter<int>(test, 10, &display);

	std::cout << "\n";
	std::cout << "Set Random Value and display \n";
	iter<int>(test, 10, &setRandomValue);
	iter<int>(test, 10, &display);


}