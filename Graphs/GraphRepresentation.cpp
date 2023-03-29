#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    // UNDIRECTED GRAPH using adjacency list
    cout << "\nEnter the number of V and E for the undirected graph: ";
    int n, m;
    cin >> n >> m;
    vector<int> *adj = new vector<int>[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // SC-> O(V + 2*E), v: Vertices, E: Edges

    // Printing the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << endl
                 << i << " " << adj[i][j];
        }
    }
    delete[] adj;

    /*
    Other way
    unordered_map<int, vector<int>> map;
    */

    /*
    if we declare a vector<vector<int>> v instead of vector<int> v[], then that is also very helpful but in that case we can change the number of vertices in the graph. But when it is declared using array of vectors then there is no chance of increasing the number of vertices in the graph, because the size of the array is fixed. Remember to free the memory allocated using new keyword.
    */

    /*
    For the correct implementation fo the graph look at the bfs code
    */

    return 0;
}