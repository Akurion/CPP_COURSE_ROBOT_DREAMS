#include "factorialwithrecurs.h"
#include <iostream>


int factorialwithrecurs(int count) {
    if (count < 0) {
        std::cout << "Number must be higher than 0" << std::endl;
        return -1;
    }
    else if (count == 0 || count == 1) {
        return 1;
    }
    else {
        return count * factorialwithrecurs(count - 1);
    }
}
