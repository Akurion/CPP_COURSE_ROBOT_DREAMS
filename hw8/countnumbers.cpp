#include "countnumbers.h"
#include <iostream>

void countnumbers(int n) {
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;
    int num;

    std::cout << "Enter " << n << " numbers: ";

    for (int i = 0; i < n; ++i) {
        std::cin >> num;

        if (num > 0) {
            positiveCount++;
        }
        else if (num < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
        }
    }

    std::cout << "Positive: " << positiveCount << ", negative: " << negativeCount << ", zeroes: " << zeroCount << std::endl;
}