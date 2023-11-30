#include "factorialwithrecurs.h"
#include <iostream>


void factorialwithrecurs(int count, int& result) {
    if (count < 0) {
        std::cout << "Number must be higher than 0" << std::endl;
    }
    else if (count == 0 || count == 1) {
        result = 1;
    }
    else {
        factorialwithrecurs(count - 1, result);
        result *= count;
    }
}
