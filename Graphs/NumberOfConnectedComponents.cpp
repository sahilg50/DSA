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
    void deleteGraph();         // delete the graph and release the memory
    vector<bool> visited;
};
Graph::Graph(int n)
{
    this->n = n;
    this->adj = new vector<int>[n];
    this->visited.resize(n, false);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::BFS(int s)
{

    queue<int> Q;
    visited[s] = true;
    Q.push(s);

    while (!Q.empty())
    {
        s = Q.front(), Q.pop();
        cout << s << " ";
        for (int it : adj[s])
        {
            if (!visited[it])
            {
                visited[it] = true;
                Q.push(it);
            }
        }
    }
}

void Graph::deleteGraph()
{
    delete[] this->adj;
}

int main()
{
    cout << endl
         << "Enter the total number of nodes and edges: ";
    int N, M;
    cin >> N >> M;
    Graph g(N);

    for (int i = 0; i < M; i++)
    {
        cout << endl
             << "Enter the edge: ";
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Following is the Breadth First Traversal ";

    // Find the number of connected components
    int components = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!g.visited[i])
        {
            g.BFS(i);
            components++;
        }
    }
    cout << endl
         << "The number of components in the graph are: " << components;

    return 0;
}

/*
BFS:
TC-> O(V + 2*E) -> Exact
SC-> O(V)
where V, E is the total number of vertices and edges respectively
*/