#include "hasCycle.h"
#include <unordered_set>

bool has_cycle(Node* head) {
    std::unordered_set<Node*> visitedNodes;

    while (head) {
        if (visitedNodes.find(head) != visitedNodes.end()) {
            return true;  
        }

        visitedNodes.insert(head);
        head = head->next;
    }

    return false;  
}
