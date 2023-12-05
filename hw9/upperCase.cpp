#include <iostream>
#include "upperCase.h"


void upperCase(char str[])
{
	int i = 0;
	std::cout << "Enter string: ";
	std::cin.getline(str, 10);
	while (str[i] != '\0')
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	std::cout << str << std::endl;
	
}