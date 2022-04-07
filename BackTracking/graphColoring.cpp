#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// non-directional graph
class Graph
{
    unordered_map<int, vector<int>> map;
    unordered_map<int, int> color_map;
    unordered_set<int> visited;

    bool isSafe(int node, int color)
    {
        for (auto i : map[node])
        {
            if (color_map.count(i))
            {
                if (color_map[i] == color)
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    void addEdge(int v, int u)
    {
        map[v].push_back(u);
        map[u].push_back(v);
    }

    int size_of_graph()
    {
        unordered_set<int> nodes;
        for (auto i : map)
        {
            nodes.insert(i.first);
            for (auto j : map[i.first])
                nodes.insert(j);
        }

        return nodes.size();
    }

    bool checkColoring(int node, int total_colors)
    {

        // base case
        if (node == size_of_graph())
        {
            return true;
        }

        auto iter = map.begin();
        for (int i = 0; i < node; i++)
            ++iter;
        int curr_node = iter->first;

        for (int i = 0; i < total_colors; i++)
        {

            if (isSafe(curr_node, i))
            {
                color_map[curr_node] = i;
                visited.insert(curr_node);
                cout << "Curren Node: " << curr_node << " Color: " << i << endl;

                if (checkColoring(node + 1, total_colors))
                    return true;

                color_map.erase(curr_node);
            }
        }
        visited.erase(curr_node);
        return false;
    }
};

int main()
{

    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(3, 5);
    g.addEdge(5, 4);

    cout << "Size of the graph: " << g.size_of_graph() << endl;
    cout << g.checkColoring(0, 2);
    return 0;
}