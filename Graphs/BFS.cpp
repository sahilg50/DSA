#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    int n;
    vector<int> *adj;

public:
    Graph(int n);               // Constructor, n is the total number of verticesin graph.
    void addEdge(int u, int v); // Method to add undirected edge between u and v.
    void BFS(int s);            // Method to print BFS traversal starting from node s.
};
Graph::Graph(int n)
{
    this->n = n;
    this->adj = new vector<int>[n];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[this->n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue<int> Q;
    visited[s] = true;
    Q.push(s);

    vector<int>::iterator it;
    while (!Q.empty())
    {
        s = Q.front(), Q.pop();
        cout << s << " ";
        for (it = adj[s].begin(); it != adj[s].end(); it++)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                Q.push(*it);
            }
        }
    }
}

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    cout << "Following is the Breadth First Traversal ";
    g.BFS(2);

    return 0;
}