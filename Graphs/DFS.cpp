#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int v; // total number of edges

    //Adjacency List
    list<int> *adj;

public:
    Graph(int v);
    //Function to add an edge to the graph
    void addEdge(int v, int w);

    //DFS traversal of the vertices reachable from v
    void DFS(int v);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int s)
{
    bool *visited = new bool[this->v];
    for (int i = 0; i < this->v; i++)
    {
        visited[i] = false;
    }

    //Mark the current node as visited and print it
    visited[s] = true;
    cout << s << " " << endl;

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
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << endl
         << "Enter the number of egdes: ";
    cin >> edges;

    Graph g(nodes);

    int x, y;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }

    cout << "Enter the node from where to start the DFS: ";
    int n;
    cin >> n;

    g.DFS(n);

    return 0;
}