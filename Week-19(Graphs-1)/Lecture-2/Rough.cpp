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
                    if (visited[nbr] && nbr != parent[frontNode])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkCyclicUsingDFS(int src, unordered_map<int, bool> visited2, int parent)
    {
        visited2[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!visited2[nbr])
            {
                bool checkans = checkCyclicUsingDFS(nbr, visited2, src);
                if (checkans == true)
                {
                    return true;
                }
            }
            if (visited2[nbr] && nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool checkCyclicDirUsingDFS(int src, unordered_map<int, bool> &visitedDirected, unordered_map<int, bool> &dfsvisited)
    {
        visitedDirected[src] = true;
        dfsvisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visitedDirected[nbr])
            {
                bool checkaagekaans = checkCyclicDirUsingDFS(nbr, visitedDirected, dfsvisited);
                if (checkaagekaans == true)
                {
                    return true;
                }
            }

            if (visitedDirected[nbr] == true && dfsvisited[nbr] == true)
            {
                return true;
            }
        }
        dfsvisited[src] = false;
        return false;
    }
};

int main()
{

    Graph<int> g;
    int n = 5;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 4, 1);
    g.printAdjList();
    cout << endl;

    // for bfs
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

    cout << "Printing for undirected BFS Traversal" << endl;
    if (ans == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cylce is absent" << endl;
    }

    // for dfs
    bool ans2 = false;
    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            ans2 = g.checkCyclicUsingDFS(i, visited2, -1);
            if (ans2 == true)
            {
                break;
            }
        }
    }

    cout << "Printing for undirected DFS traversal" << endl;
    if (ans2 == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is absent" << endl;
    }

    // for directed graph dfs
    unordered_map<int, bool> visitedDirected;
    unordered_map<int, bool> dfsvisited;
    bool ansDir = false;

    for (int i = 0; i < n; i++)
    {
        if (!visitedDirected[i])
        {
            ansDir = g.checkCyclicDirUsingDFS(i, visitedDirected, dfsvisited);
            if (ansDir == true)
            {
                break;
            }
        }
    }

    cout << "Printing for Directed DFS traversal" << endl;
    if (ansDir == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is absent" << endl;
    }
}