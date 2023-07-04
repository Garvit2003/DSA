#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
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

    void bfs(T src)
    {
        queue<T> q;
        // creating a map for visited nodes
        unordered_map<T, bool> visited;

        // source node ko queue mein push kr diya
        q.push(src);
        // aur fir usse true mark kr diya visited wale map mein
        visited[src] = true;

        // loop tab tak chalega jab tak queue empty ni ho jati
        while (!q.empty())
        {
            // step 1L frontnode nikalo
            int frontnode = q.front();
            // step 2:frontnode ko pop kro
            q.pop();
            // step 3:Print frontnode
            cout << frontnode << ",";

            // step 4:insert neighbours
            for (auto neighbour : adjList[frontnode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main()
{
    // int n;
    // cout << "Enter the number of nodes: ";
    // cin >> n;

    // vector<vector<int>> adj(n, vector<int>(n, 0));

    // int e;
    // cout << "Enter the number of edges: ";
    // cin >> e;

    Graph<int> g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(3, 7, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(7, 4, 0);
    g.printAdjacencyList();
    cout << endl;
    g.bfs(0);
}