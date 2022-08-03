#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int N;                                 // Number of nodes
    vector<int> *adj;                      // adjacency list
    vector<int> colorMap;                  // To assign colors to nodes
    bool isSafe(int node, int curr_color); // To check if the current color can be assigned to the node or not

public:
    Graph(int n);                                  // constructor
    void addEdge(int u, int v);                    // undirected graph
    bool graphColoring(int node, int total_color); // To check if the nodes of the graph can be colored using M colors or not

    ~Graph()
    {
        delete[] this->adj;
    }
};
Graph::Graph(int n)
{
    this->N = n;
    this->adj = new vector<int>[N];
    this->colorMap.resize(N, -1);
}
void Graph::addEdge(int u, int v)
{
    this->adj[u].push_back(v);
    this->adj[v].push_back(u);
}

bool Graph::isSafe(int node, int curr_color)
{
    if (colorMap[node] != -1)
        return false;
    for (auto neighbor : this->adj[node])
    {
        if (colorMap[neighbor] == curr_color)
            return false;
    }
    return true;
}

bool Graph::graphColoring(int node, int total_color)
{
    // Base Case
    if (node == this->N)
        return true;

    for (int c = 0; c < total_color; c++)
    {
        if (isSafe(node, c))
        {
            colorMap[node] = c;
            if (graphColoring(node + 1, total_color))
                return true;
            colorMap[node] = -1;
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
    cout << "\nEnter the edges: " << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << endl
         << "Enter the total number of colors available: ";
    int m;
    cin >> m;
    cout << g.graphColoring(0, m);
    return 0;
}

/*
TC-> O(m^N)
SC-> O(N), m is the total colors and N is the total number of nodes in the graph
*/