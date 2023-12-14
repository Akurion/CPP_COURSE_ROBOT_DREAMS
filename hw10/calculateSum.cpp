#include <iostream>
#include "calculatesum.h"

bool calculateSum(const double* arr, int arrSize, double& sum)
{
	if (arrSize <= 0)
		return false;
	else
	{
		for (int i = 0; i < arrSize; i++)
		{
			sum += arr[i];
		}
		return true;
	}
}