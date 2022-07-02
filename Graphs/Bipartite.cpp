#include <iostream>
#include <vector>
#include <algorithm>
#include <Queue>

using namespace std;

class Graph
{
private:
    int n;
    vector<int> *adj;

public:
    Graph(int n);               // Constructor, n is the total number of verticesin graph.
    void addEdge(int u, int v); // Method to add undirected edge between u and v.
    // bool bfsCheck(int src);     // Method to print BFS traversal starting from node s.
    void deleteGraph(); // delete the graph and release the memory
    vector<bool> visited;

    ~Graph()
    {
        cout << endl
             << "Destructor is called: ";
        delete[] this->adj;
    }
};
Graph::Graph(int n)
{
    cout << endl
         << "Constructor is called: ";
    this->n = n;
    this->adj = new vector<int>[n];
    this->visited.resize(n, false);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// bool Graph::bfsCheck(int src)
// {
//     queue<int> q;
//     q.push(src);
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//     }
// }

int main()
{
    Graph g(10);
    return 0;
}