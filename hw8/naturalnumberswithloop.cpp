#include "naturalnumberswithloop.h"
#include <iostream>

void naturalnumberswithloop(int count) {
    if (count <= 0) {
        std::cout << "Natural numbers must be higher than 0" << std::endl;
        return;
    }

    for (int i = count; i >= 1; --i) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    for (int i = 1; i <= count; i++)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}
