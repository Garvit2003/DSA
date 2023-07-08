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

    // FOR BFS
    bool checkCyclicUsingBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            for (auto nbr : adjList[frontnode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontnode;
                }
                else
                {
                    // already visited
                    if (nbr != parent[frontnode])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // FOR DFS
    bool checkCyclicUsingDFS(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool checkaageKaAns = checkCyclicUsingDFS(nbr, visited, src);
                if (checkaageKaAns == true)
                {
                    return true;
                }
            }
            if (visited[nbr] && nbr != parent)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    Graph<int> g;
    int n = 5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);
    g.printAdjacencyList();
    cout << endl;

    // For BFS
    bool ans = false;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicUsingBFS(i, visited);
            if (ans == true)
            {
                break;
            }
        }
    }

    cout << "Printing for BFS traversal" << endl;
    if (ans == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is absent" << endl;
    }

    // for DFS

    bool ansDFS = false;
    unordered_map<int, bool> visitedDFS;
    for (int i = 0; i < n; i++)
    {
        if (!visitedDFS[i])
        {
            ans = g.checkCyclicUsingDFS(i, visitedDFS, -1);
            if (ansDFS == true)
            {
                break;
            }
        }
    }
    cout << "Printing for BFS traversal" << endl;
    if (ansDFS == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is absent" << endl;
    }
}