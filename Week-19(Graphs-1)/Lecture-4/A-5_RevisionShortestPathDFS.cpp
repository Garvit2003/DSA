#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool direction)
    {
        adjList[u].push_back({v, weight});
        if (direction == 0)
        {
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto nbr : node.second)
            {
                cout << "(" << nbr.first << "," << nbr.second << "),";
            }
            cout << endl;
        }
    }

    void topoSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                topoSortDFS(nbr.first, visited, ans);
                visited[nbr.first] = true;
            }
        }
        cout << "Pushing" << src << endl;
        ans.push(src);
    }

    void shortestPathDFS(int destination, stack<int> &ans, int n)
    {

        vector<int> distance(n, INT_MAX);
        int src = ans.top();
        ans.pop();
        distance[src] = 0;

        for (auto nbr : adjList[0])
        {
            if (distance[0] + nbr.second < distance[nbr.first])
            {
                distance[nbr.first] = nbr.second + distance[0];
            }
        }

        while (!ans.empty())
        {
            int frontnode = ans.top();
            ans.pop();
            if (distance[frontnode] != INT_MAX)
            {
                for (auto nbr : adjList[frontnode])
                {
                    if (distance[frontnode] + nbr.second < nbr.first)
                    {
                        nbr.first = nbr.second + distance[frontnode];
                    }
                }
            }
        }

        cout << "Printing ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" distance[i] << " " << endl;
        }
    }
};

int main()
{
    graph<int> g;
    int n = 5;

    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);

    g.printAdjList();

    unordered_map<int, bool> visited;
    stack<int> topoOrder;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topoSortDFS(0, visited, topoOrder);
        }
    }
    // g.topoSortDFS(0, visited, topoOrder);

    cout << "Printing topoOrder" << endl;
    while (!topoOrder.empty())
    {
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }

    cout << endl;

    g.shortestPathDFS(3, topoOrder, n);
}