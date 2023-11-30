#include "naturalnumberswithrecur.h"
#include <iostream>

void naturalnumberswithrecurdesc(int count)
{
	if (count <= 0)
		return;

	if (count > 0)
	{
		std::cout << count << " ";
		naturalnumberswithrecurdesc(count - 1);
	}
	else
	{
		std::cout << std::endl;
	}
}

void naturalnumberswithrecurasc(int count) {
	if (count <= 0)
		return;

	for (int i = 1; i <= count; ++i) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
}

