#pragma once
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(int vertices, ConnectionType type = ConnectionType::undirected)
		: m_vertices(vertices), m_connectionType(type) {}

	virtual void addEdge(int v, int w) = 0;
	virtual void BFS(int vertex = 0) {};
	virtual void DFS(int vertex = 0) {};
	virtual int numberOfNodesInLevel(int level) = 0;
	virtual bool isStronglyConnected() const = 0; 
	

protected:
	int m_vertices;
	ConnectionType m_connectionType;
};


class GraphAdjList : public Graph
{
public:
	GraphAdjList(int vertices, ConnectionType type = ConnectionType::undirected);
	void addEdge(int v, int w) override;
	void BFS(int vertex = 0) override;
	int numberOfNodesInLevel(int level) override; 
	bool isStronglyConnected() const override;

private:
	std::vector<std::list<int>> m_list;
	void DFSUtil(int vertex, std::vector<bool>& visited) const;
};

class GraphAdjMatrix : public Graph
{
	using Graph::Graph;

	void addEdge(int v, int w) override {};
	void DFS(int vertex = 0) override {};


};

