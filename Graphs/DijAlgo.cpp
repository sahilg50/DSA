#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

struct edge
{
    string name;
    int weight;
};

class Graph
{
    map<string, vector<edge>> m;

public:
    void addEdgde(string u, string v, int dist, bool bidir = true)
    {
        m[u].push_back({v, dist});
        if (bidir)
        {
            m[v].push_back({u, dist});
        }
    }

    void printAdj()
    {
        for (auto j : m)
        {
            cout << j.first << "->";
            string s = j.first;
            for (auto i = m[s].begin(); i != m[s].end(); i++)
            {
                cout << "(" << (*i).name << "," << (*i).weight << ")";
            }
            cout << endl;
        }
    }

    void dijkstra(string src)
    {
        map<string, int> dist;
        //set all distances to infinity
        for (auto j : m)
        {
            dist[j.first] = INT_MAX;
        }

        //set to find out the node with the minimum distance
        set<pair<int, string>> s;
        dist[src] = 0;
        s.insert(make_pair(0, src));

        while (!s.empty())
        {
            //Find the pair at the front
            auto p = *(s.begin());
            auto node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            //Iterate over the neighbors of the current node
            for (auto childPair : m[node])
            {
                if (nodeDist + childPair.weight < dist[childPair.name])
                {
                    //In the set updation of a particular is not possible
                    // we have to remove the old pair, and insert the new pair to simulation updation
                    string destination = childPair.name;
                    auto f = s.find(make_pair(dist[destination], destination));
                    if (f != s.end())
                    {
                        s.erase(f);
                    }

                    //insert the new pair
                    dist[destination] = nodeDist + childPair.weight;
                    s.insert(make_pair(dist[destination], destination));
                }
            }
        }
        for (auto d : dist)
        {
            cout << d.first << " is located at distance of " << d.second << endl;
        }
    }
};

int main()
{

    Graph g;
    g.addEdgde("A", "B", 10);
    g.addEdgde("A", "C", 20, false);
    g.printAdj();
    return 0;
}