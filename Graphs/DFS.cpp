#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph
{
    unordered_map<int, vector<int>> map;

public:
    void addEdge(int u, int v)
    {
        map[u].push_back(v);
    }

    int size()
    {
        unordered_map<int, bool> nodes;
        for (auto i : map)
        {
            nodes[i.first] = true;
            for (auto j : map[i.first])
                nodes[j] = true;
        }

        return nodes.size();
    }
};

int main()
{

    Graph graph;
    graph.addEdge(1, 2);
    graph.addEdge(1, 9);
    graph.addEdge(1, 8);
    graph.addEdge(2, 5);

    cout << graph.size();
    return 0;
}
