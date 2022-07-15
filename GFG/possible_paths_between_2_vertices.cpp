
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int destination, int &count, vector<bool> &visited)
    {
        if (node == destination)
        {
            count++;
            visited[destination] = false;
            return;
        }
        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                dfs(neighbor, adj, destination, count, visited);
            }
        }
        visited[node] = false;
    }

public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination)
    {
        vector<bool> visited(V, false);
        int count = 0;
        visited[source] = true;
        dfs(source, adj, destination, count, visited);
        return count;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> *adj = new vector<int>[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}