#include <iostream>
#include "parseStringLetters.h"

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount)
{
	vowelsCount = 0;
	consonantsCount = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		char currentchar = std::tolower(str[i]);

		if ((currentchar >= 'a' && currentchar <= 'z')) {
			if (currentchar == 'a' || currentchar == 'e' || currentchar == 'i' || currentchar == 'o' || currentchar == 'u')
				vowelsCount++;
			else
				consonantsCount++;
		}
	}
	std::cout << "Vowels number : " << vowelsCount << std::endl;
	std::cout << "Consonants number : " << consonantsCount << std::endl;
}