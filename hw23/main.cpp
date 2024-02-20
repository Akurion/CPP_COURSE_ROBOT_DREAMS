#include <iostream>
#include "uniqueWordsCount.h"
#include "mostOccuredWord.h"
#include "areBracketsBalanced.h"
#include "hasCycle.h"

int main() {
    // task 1
    std::string line1 = "Hello Hey Hello Bye Hey";
    unsigned int count = uniqueWordsCount(line1);
    std::cout << "Number of unique words: " << count << std::endl;

    // task 2
    std::string line2 = "Hello Hey Hello Bye Hey";
    std::string mostOccurred = mostOccuredWord(line2);
    std::cout << "Most occurred word: " << mostOccurred << std::endl;

    // task 3
    std::string balancedExpression = "{[()]}";
    std::string unbalancedExpression = "[{]}";
    std::cout << "Balanced: " << areBracketsBalanced(balancedExpression) << std::endl;
    std::cout << "Unbalanced: " << areBracketsBalanced(unbalancedExpression) << std::endl;

    // task 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;

    bool hasCycle = has_cycle(head);
    std::cout << "Has cycle: " << hasCycle << std::endl;

    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
