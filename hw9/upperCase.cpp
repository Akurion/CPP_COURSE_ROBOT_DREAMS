#include <iostream>
#include "upperCase.h"


void upperCase(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = std::toupper(str[i]);
        i++;
    }
}