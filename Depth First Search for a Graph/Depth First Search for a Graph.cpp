// Depth First Search for a Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<list>

using namespace std;

class Graph
{
private:

	int V;
	list<int> *adj;

	void DFSutil(int v, bool visited[]);

public:
	Graph(int V);

	void addEdge(int v, int w);
	void DFS(int v);
};


int main()
{
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal" 
		" (starting from vertex 2) \n";

	g.DFS(2);

    return 0;
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::DFSutil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSutil(*i, visited);
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSutil(v, visited);
}






