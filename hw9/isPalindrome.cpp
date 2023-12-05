#include <iostream>
#include "isPalindrome.h"

bool isPalindrome(const char str[]) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char leftChar = std::tolower(str[i]);
        char rightChar = std::tolower(str[j]);

        while (!std::isalpha(leftChar) && i < j) {
            i++;
            leftChar = std::tolower(str[i]);
        }

        while (!std::isalpha(rightChar) && i < j) {
            j--;
            rightChar = std::tolower(str[j]);
        }

        if (leftChar != rightChar) {
            return false;  
        }
    }

    return true;
}