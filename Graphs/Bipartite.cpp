#include <iostream>
#include <vector>
#include <algorithm>
#include <Queue>
#include <unordered_map>

using namespace std;

class Graph
{
private:
    int n;
    vector<int> *adj;

public:
    Graph(int n);               // Constructor, n is the total number of vertices in graph.
    void addEdge(int u, int v); // Method to add undirected edge between u and v.
    bool bipartiteBfs(int src); // Method to print BFS traversal starting from node s.
    bool checkBipartite();
    unordered_map<int, int> color; // unordered_map<node, color>

    ~Graph() // Destructor
    {
        cout << endl
             << "Destructor deallocated the memory allocated by object of this class: ";
        delete[] this->adj;
    }
};
Graph::Graph(int n)
{
    cout << endl
         << "Constructor created an object of class Graph: ";
    this->n = n;
    this->adj = new vector<int>[n];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    this->color[u] = -1;
    this->color[v] = -1;
}

bool Graph::bipartiteBfs(int src)
{
    queue<int> q;
    q.push(src);
    this->color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (this->color[it] == -1)
            {
                q.push(it);
                this->color[it] = 1 - this->color[node];
            }
            else if (this->color[it] == this->color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool Graph::checkBipartite()
{

    for (int i = 0; i < this->n; i++)
    {
        if (this->color[i] == -1)
        {
            if (!bipartiteBfs(i))
                return false;
        }
    }
    return true;
};

int main()
{
    // This code will check for all the components of the graph because checkBipartite will take care of disconnected components
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

    bool flag = g.checkBipartite();
    if (flag == false)
        cout << "False";
    else
        cout << "True";

    return 0;
}