#include <iostream>
#include <vector>
#include <algorithm>

unsigned int countDivisibleBy(const std::vector<int>& vec, int number);

bool compareByLength(const std::string& str1, const std::string& str2) {
    return str1.length() < str2.length();
}

class LengthComparator {
public:
    bool operator()(const std::string& str1, const std::string& str2) const {
        return str1.length() < str2.length();
    }
};

int main() {
    std::vector<std::string> stringContainer = { "apple", "banana", "kiwi", "orange", "grape" };


    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);


    std::cout << "Sorted strings (using function): ";
    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;


    std::sort(stringContainer.begin(), stringContainer.end(), LengthComparator());


    std::cout << "Sorted strings (using functional object): ";
    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::sort(stringContainer.begin(), stringContainer.end(), [](const std::string& str1, const std::string& str2) {
        return str1.length() < str2.length();
        });

    std::cout << "Sorted strings (using lambda): ";
    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;


    int number = 5;
    unsigned int count = countDivisibleBy({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, number);

    std::cout << "Number of elements divisible by " << number << ": " << count << std::endl;

    return 0;
}

unsigned int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(), [number](int element) {
        return element % number == 0;
        });
}
