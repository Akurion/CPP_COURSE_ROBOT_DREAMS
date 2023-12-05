#include <iostream>
#include "translateArray.h"
#include "upperCase.h"
#include "isEqual.h"
#include "parseStringLetters.h"
#include "isPalindrome.h"


int main()
{
    // 1
    const int SIZE = 10;
    int array[SIZE];

    translateArray(array, SIZE);
    std::cout << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // 2
    char str[10];

    upperCase(str);
    std::cout << std::endl;  

    // 3

    const char str3[] = "abba";

    if (isPalindrome(str3))
        std::cout << "The string is a palindrome" << std::endl;
    else
        std::cout << "The string is not a palindrome" << std::endl;

    std::cout << std::endl;

    // 4   
    int vowels = 0;
    int consonants = 0;
    const char str4[6] = { 'a', 'b', 'c', 'd', 'e','i' };

    parseStringLetters(str4, vowels, consonants);
    
    std::cout << std::endl;

    // 5
    const char str1[3] = {'z', 'x', 'c'};
    const char str2[3] = {'z', 'x', 'c'};

    if (isEqual(str1, str2))
        std::cout << "The strings are equal" << std::endl;
    else
        std::cout << "The strings aren't equal" << std::endl; 
}

