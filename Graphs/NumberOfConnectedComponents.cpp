#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    //number of nodes in graph
    int v;
    list<int> *adj;

public:
    bool *visited;

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
    visited[s] = true;

    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}

int main()
{

    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);
    g.addEdge(4, 5);

    g.initializeNotVisited();

    int connectedComponents = 0;
    for (int i = 0; i < 6; i++)
    {
        if (g.visited[i] == false)
        {
            g.DFS(i);
            connectedComponents++;
        }
    }

    cout << connectedComponents << " ";

    return 0;
}