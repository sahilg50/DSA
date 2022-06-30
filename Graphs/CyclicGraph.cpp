#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Graph
{
private:
    int n;            // number of nodes
    vector<int> *adj; // adjacency list
public:
    Graph(int n);
    void addEdge(int u, int v);
    vector<bool> visited;
    bool isCyclic(int s); // Method to check for cyclic graph in undirected graph
    void deleteGraph();
};

Graph::Graph(int n)
{
    this->n = n;
    this->adj = new vector<int>[n];
    this->visited.resize(n, false);
};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool Graph::isCyclic(int s)
{
    // Create a queue for BFS
    queue<pair<int, int>> q;
    q.push({s, -1});
    visited[s] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push({it, node});
            }
            else if (par != it)
                return true;
        }
    }
    return false;
}

void Graph::deleteGraph()
{
    delete[] this->adj;
}
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 2);

    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        if (!g.visited[i])
        {
            if (g.isCyclic(i) == true)
                flag = true;
        }
    }
    cout << flag;
    g.deleteGraph();
    return 0;
}