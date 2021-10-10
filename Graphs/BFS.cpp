//Creating a graph using adjacent list and then apply the code for BFS.

#include <iostream>
#include <list>

using namespace std;

class Graph
{

    int v; //total numnber of vertices

    //Pointer to an array containing adjacency lists
    list<int> *adj;

public:
    Graph(int v); //Constructor

    //Funtion to add edge to the graph
    void addEdge(int v, int w);

    //Prints BFS traversal from a given source s
    void BFS(int s);
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

void Graph::BFS(int s)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)

        visited[i] = false;

    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex

    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is the Breadth First Traversal ";
    g.BFS(2);
}