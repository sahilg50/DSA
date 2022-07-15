#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

// A directed graph using adjacency list
// representation
class Graph
{

    // No. of vertices in graph
    int V;
    list<int> *adj;

    // A recursive function
    // used by countPaths()
    void countPathsUtil(int, int, bool[],
                        int &);

public:
    // Constructor
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);

    ~Graph()
    {
        delete[] this->adj;
    }
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V + 1];
}

void Graph::addEdge(int u, int v)
{

    // Add v to u’s list.
    adj[u].push_back(v);
}

// Returns count of paths from 's' to 'd'
int Graph::countPaths(int s, int d)
{

    // Mark all the vertices
    // as not visited
    bool *visited = new bool[V];
    memset(visited, false, sizeof(visited));

    // Call the recursive helper
    // function to print all paths
    int pathCount = 0;
    countPathsUtil(s, d, visited, pathCount);
    return pathCount;
}

// A recursive function to print all paths
// from 'u' to 'd'. visited[] keeps track of
// vertices in current path. path[] stores
// actual vertices and path_index is
// current index in path[]
void Graph::countPathsUtil(int u, int d, bool visited[],
                           int &pathCount)
{
    visited[u] = true;

    // If current vertex is same as destination,
    // then increment count
    if (u == d)
        pathCount++;

    // If current vertex is not destination
    else
    {
        // Recur for all the vertices adjacent to
        // current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                countPathsUtil(*i, d, visited,
                               pathCount);
    }

    visited[u] = false;
}

// Driver Code
int main()
{

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        Graph g(N);
        for (int i = 2; i < N; i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    g.addEdge(i, j);
                }
            }
        }
        cout << g.countPaths(1, N) << endl;
    }

    return 0;
}