#include <iostream>
#include "translateArray.h"

void translateArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0)
            array[i] *= 2;
        else if (array[i] < 0)
            array[i] = 0;
    }
    std::cout << std::endl;
}