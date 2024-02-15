#include <iostream>
#include "Graph.h"

#define TIME_LOG_ENABLED
int getTime() { return 1; }

int main()
{
	GraphAdjList graph(11);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);

	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(3, 7);
	
	graph.addEdge(4, 8);
	graph.addEdge(5, 9);
	graph.addEdge(7, 10);
	graph.addEdge(6, 9);
	graph.addEdge(1, 9);
	graph.addEdge(1, 3);

#ifdef TIME_LOG_ENABLED
    int startTime = getTime();
#endif
	int nodesCount = graph.numberOfNodesInLevel(2); 
	std::cout << "Number of nodes at level 2: " << nodesCount << std::endl;
    bool isConnected = graph.isStronglyConnected();

    if (isConnected)
    {
        std::cout << "The graph is strongly connected." << std::endl;
    }
    else
    {
        std::cout << "The graph is not strongly connected." << std::endl;
    }

#ifdef TIME_LOG_ENABLED
    int endTime = getTime();
    int diff = endTime - startTime;
    std::cout << "\nTime used for checking strong connectivity: " << diff << " milliseconds" << std::endl;
#endif

    return 0;
}