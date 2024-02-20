#include "mostOccuredWord.h"
#include <unordered_map>
#include <sstream>

std::string mostOccuredWord(const std::string& line) {
    std::unordered_map<std::string, int> wordFrequency;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
        wordFrequency[word]++;
    }

    int maxFrequency = 0;
    std::string mostOccurredWord;

    for (const auto& pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostOccurredWord = pair.first;
        }
    }

    return mostOccurredWord;
}
