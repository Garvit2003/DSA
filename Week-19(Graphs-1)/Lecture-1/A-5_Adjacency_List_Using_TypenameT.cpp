#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    // how to add edge in a list
    void addEdge(T u, T v, bool direction)
    {
        // direction=0->undirected graph
        // direction=1->directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('a', 'c', 0);
    g.printAdjacencyList();
}