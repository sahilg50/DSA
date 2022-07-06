#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
/*
Key points:
- This is the code for directed cyclic graph
- Add the nodes atart from 0, i.e. follow 0 based indexing
*/
class Graph
{
private:
    int n;            // number of nodes
    vector<int> *adj; // Adjacency list
public:
    Graph(int n);
    void addEdge(int u, int v);                 // Undirected Graph
    bool DFS(int src, int vis[], int dfsVis[]); // method to perform dfs starting from src
    bool isCyclic();                            // Method to check if the graph is cyclic or not

    ~Graph()
    {
        delete[] this->adj;
    }
};

Graph::Graph(int n)
{
    this->n = n;
    adj = new vector<int>[n];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

bool Graph::DFS(int src, int vis[], int dfsVis[])
{
    vis[src] = 1;
    dfsVis[src] = 1;
    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            if (DFS(it, vis, dfsVis))
                return true;
        }
        else if (dfsVis[it])
            return true;
    }
    dfsVis[src] = 0;
    return false;
}

bool Graph::isCyclic()
{
    int *vis = new int[this->n];
    int *dfsVis = new int[this->n];

    memset(vis, 0, sizeof(int) * this->n);
    memset(dfsVis, 0, sizeof(int) * this->n);

    for (int i = 0; i < this->n; i++)
    {
        if (!vis[i])
        {
            if (DFS(i, vis, dfsVis))
                return true;
        }
    }

    return false;
}

int main()
{
    cout << "\nEnter the total number of nodes and edges: ";
    int V, E;
    cin >> V >> E;
    Graph g(V);
    cout << "\nEnter the edges:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.isCyclic())
        cout << "\nThe graph contains a cycle! ";
    else
        cout << "\nNo cycle!";

    return 0;
}