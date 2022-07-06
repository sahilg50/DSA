#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int N;            // number of nodes
    vector<int> *adj; // Adjacency list
public:
    Graph(int n);
    void addEdge(int u, int v); // Undirected Graph

    ~Graph()
    {
        delete[] this->adj;
    }
};

Graph::Graph(int n)
{
    this->N = n;
    adj = new vector<int>[N];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    cout << "\nEnter the total number of nodes and edges: ";
    int V, E;
    cin >> V >> E;
    Graph g(V);
    cout << "\nEnter the edges: ";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    return 0;
}