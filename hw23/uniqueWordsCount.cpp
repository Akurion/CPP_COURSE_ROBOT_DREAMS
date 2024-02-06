#include "uniqueWordsCount.h"
#include <unordered_set>
#include <sstream>

unsigned int uniqueWordsCount(const std::string& line) {
    std::unordered_set<std::string> uniqueWords;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}
