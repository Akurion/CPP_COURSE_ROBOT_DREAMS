#include <iostream>
#include "translateArray.h"

void translateArray(int array[], int size)
{
    int number = 0;
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Enter number for element in array: ";
        std::cin >> number;
        array[i] = number;
        if (array[i] > 0)
            array[i] *= 2;
        else if (array[i] < 0)
            array[i] = 0;
    }
    std::cout << std::endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}