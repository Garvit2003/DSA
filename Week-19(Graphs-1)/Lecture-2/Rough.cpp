#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
#define pb push_back

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    // adding edge
    void addEdge(T u, T v, bool direction)
    {
        // adjList(u).pb(v);
        // if (direction == 0)
        // {
        //     adjList(v).pb(u);
        // }
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto nbr : node.second)
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }

    bool checkCyclicUsingBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<T> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr] = frontNode;
                    visited[nbr] = true;
                }
                else
                {
                    if (nbr != parent[frontNode])
                    {
                        return true;
                    }
                }
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
    g.printAdjList();
    cout << endl;

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

    if (ans == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cylce is absent" << endl;
    }
}