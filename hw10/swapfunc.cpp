#include <iostream>
#include "swapfunc.h"

void swapbyref(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;

	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
}

void swapbypoint(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	std::cout << "A: " << *a << std::endl;
	std::cout << "B: " << *b << std::endl;
}