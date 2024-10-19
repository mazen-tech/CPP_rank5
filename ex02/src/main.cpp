#include "../header/array.hpp"
#include <iostream>
#include <cstdlib>


int main()
{
    try
    {
        // Create an array of size 5 with default constructor
        array<int> arr1(5);
        
        // Set values for the array using the [] operator
        for (int i = 0; i < 5; i++)
        {
            arr1[i] = i * 10;
        }

        // Display the array using the overloaded << operator
        std::cout << "arr1: " << arr1 << std::endl;

        // Copy constructor test
        array<int> arr2(arr1);
        std::cout << "arr2 (copied from arr1): " << arr2 << std::endl;

        // Assignment operator test
        array<int> arr3;
        arr3 = arr1;
        std::cout << "arr3 (assigned from arr1): " << arr3 << std::endl;

        // Access and modify array elements
        arr1[2] = 999;
        std::cout << "arr1 after modifying index 2: " << arr1 << std::endl;

        // Size method test
        std::cout << "Size of arr1: " << arr1.Size() << std::endl;

        // Test out-of-bounds access
        std::cout << "Trying to access arr1[10] (out-of-bounds):" << std::endl;
        std::cout << arr1[10] << std::endl; // This should throw an exception

    }
    catch (const std::exception &e)
    {
        // Catch any exceptions thrown by the array class
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}