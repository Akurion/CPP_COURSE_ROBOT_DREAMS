#include <iostream>
#include "isPalindrome.h"
#include <cstring>
#include <cctype>

bool isAlphanumeric(char ch) {
    return std::isalnum(static_cast<unsigned char>(ch)) != 0;
}

bool isPalindrome(const char str[]) {
    int length = strlen(str);

    for (int i = 0, j = length - 1; i < j; ) {
        char leftChar = std::tolower(str[i]);
        char rightChar = std::tolower(str[j]);

        while (!isAlphanumeric(leftChar) && i < j) {
            i++;
            leftChar = std::tolower(str[i]);
        }

        while (!isAlphanumeric(rightChar) && i < j) {
            j--;
            rightChar = std::tolower(str[j]);
        }

        if (leftChar != rightChar) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}