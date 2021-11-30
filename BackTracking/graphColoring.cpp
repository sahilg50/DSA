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

            return nodes.size();
        }
    }

    bool checkColoring(int curr_node, int total_covered, int total_colors)
    {
        //base case
        if (total_covered == 4)
        {
            return true;
        }
        cout << size_of_graph() << endl;

        for (int i = 0; i < total_colors; i++)
        {

            if (isSafe(curr_node, i))
            {
                color_map[curr_node] = i;
                visited.insert(curr_node);
                cout << "Curren Node: " << curr_node << " Color: " << i << endl;
                for (auto j : map[curr_node])
                {

                    if (visited.count(j) == 0)
                    {
                        cout << "Tried: " << j << endl;

                        bool nextColorAssignKarPaye = checkColoring(j, total_covered + 1, total_colors);
                        if (nextColorAssignKarPaye)
                        {
                            return true;
                        }
                    }
                }
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

    // cout << g.size_of_graph();
    cout << g.checkColoring(1, 0, 10);
    return 0;
}