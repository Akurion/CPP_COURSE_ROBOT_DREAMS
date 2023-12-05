#include <iostream>
#include "isEqual.h"

bool isEqual(const char str1[], const char str2[])
{
	for (int i = 0; i < 3; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}