#include <iostream>
#include "findelement.h"

bool find(const int* arr, int size, int elem)
{
	const int* endPtr = arr + size;

	while (arr < endPtr)
	{
		if (*arr == elem)
			return true;
		arr++;
	}
	return false;
}