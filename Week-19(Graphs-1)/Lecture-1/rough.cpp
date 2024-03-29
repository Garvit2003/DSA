#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    // adding edge
    void addEdge(int u, int v, bool direction)
    {
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

    void bfs(int src, unordered_map<int, bool> visited)
    {

        queue<int> q;

        // insert src into queue
        q.push(src);
        // mark visited true
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << ",";

            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> visited2)
    {
        cout << src << ",";
        visited2[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited2[nbr])
            {
                dfs(nbr, visited2);
            }
        }
    }
};

int main()
{

    Graph<int> g;
    int n = 8;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(3, 7, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(7, 4, 0);
    g.printAdjList();
    cout << endl;

    cout << "Printing for BFS traversal" << endl;

    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }
    cout << endl;

    cout << "Printing for DFS traversal" << endl;

    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }
}