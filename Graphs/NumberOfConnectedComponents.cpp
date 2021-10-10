#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    //number of nodes in graph
    int v;
    list<int> *adj;
    bool *visited;

public:
    Graph(int v); //constructor for the graph

    void addEdge(int v, int w); //Add edges to the graph

    //Initialize all the nodes as not visited.
    void initializeNotVisited();

    //DFS
    void DFS(int s);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
    visited = new bool[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::initializeNotVisited()
{
    for (int i = 0; i < this->v; i++)
    {
        visited[i] = false;
    }
}

void Graph::DFS(int s)
{
}

int main()
{

    return 0;
}