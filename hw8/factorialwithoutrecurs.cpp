#include "factorialwithoutrecurs.h"
#include <iostream>


void factorialwithoutrecurs(int count)
{
	int factorial = 1;
	if (count < 0)
		std::cout << "Number must be higher than 0" << std::endl;
	else
	{
		for (int i = 2; i <= count; ++i)
		{
			factorial *= i;
		}
		std::cout << "Factorial without recursio: " << factorial << std::endl;
	}
}