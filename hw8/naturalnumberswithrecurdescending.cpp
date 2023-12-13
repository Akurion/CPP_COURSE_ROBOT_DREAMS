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
}


void naturalnumberswithrecurasc(int count) {
	if (count > 0) {
		naturalnumberswithrecurasc(count - 1);
		std::cout << count << " ";
	}
	else {
		std::cout << std::endl;
	}
}
