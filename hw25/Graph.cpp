#include "Graph.h"

GraphAdjList::GraphAdjList(int vertices, ConnectionType type)
	: Graph(vertices, type)
{
	m_list.resize(vertices);
}

void GraphAdjList::addEdge(int v, int w)
{
	if (v >= 0 && v < m_vertices && w >= 0 && w < m_vertices)
	{
		m_list[v].push_back(w);
		if (m_connectionType == ConnectionType::undirected)
		{
			m_list[w].push_back(v);
		}
	}
}


void GraphAdjList::BFS(int vertex)
{
	std::vector<bool> visited;
	visited.resize(m_vertices, false);

	std::list<int> queue;

	visited[vertex] = true;
	queue.push_back(vertex);

	while (!queue.empty())
	{
		int currentVertex = queue.front();
		
		std::cout << currentVertex << " ";
		
		queue.pop_front();

		for (int adjacent : m_list[currentVertex])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}
int GraphAdjList::numberOfNodesInLevel(int level)
{
	if (level < 0 || level >= m_vertices)
	{
		std::cerr << "Invalid level for calculating the number of nodes." << std::endl;
		return 0;
	}

	std::vector<bool> visited(m_vertices, false);
	std::list<int> bfsQueue;

	visited[0] = true;
	bfsQueue.push_back(0);

	int currentLevel = 0;
	int nodesInCurrentLevel = 0;

	while (!bfsQueue.empty() && currentLevel <= level)
	{
		nodesInCurrentLevel = bfsQueue.size();

		for (int i = 0; i < nodesInCurrentLevel; ++i)
		{
			int currentVertex = bfsQueue.front();
			bfsQueue.pop_front();

			for (int adjacent : m_list[currentVertex])
			{
				if (!visited[adjacent])
				{
					visited[adjacent] = true;
					bfsQueue.push_back(adjacent);
				}
			}
		}

		if (currentLevel == level)
		{
			return nodesInCurrentLevel;
		}

		++currentLevel;
	}


	return 0;
}
bool GraphAdjList::isStronglyConnected() const
{
	for (int i = 0; i < m_vertices; ++i)
	{
		std::vector<bool> visited(m_vertices, false);
		DFSUtil(i, visited);

		for (bool isVisited : visited)
		{
			if (!isVisited)
			{
				return false;
			}
		}
	}

	return true;
}

void GraphAdjList::DFSUtil(int vertex, std::vector<bool>& visited) const
{
	visited[vertex] = true;

	for (int adjacent : m_list[vertex])
	{
		if (!visited[adjacent])
		{
			DFSUtil(adjacent, visited);
		}
	}
}
