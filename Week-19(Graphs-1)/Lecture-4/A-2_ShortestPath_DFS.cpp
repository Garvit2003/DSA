#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
// #define pb push_back;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(T v, T u, int weight, bool direction)
    {
        // direction=0- Undirected graph
        // direction=1- Directed graph
        adjList[v].push_back({u, weight});
        if (direction == 0)
        {
            adjList[u].push_back({v, weight});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "->";
            for (auto nbr : i.second)
            {
                cout << "(" << nbr.first << ",";
                cout << nbr.second << "),";
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
        cout << "Pushing " << src << endl;
        ans.push(src);
    }

    void shortestPathDFS(int destination, stack<int> topoOrder, int n)
    {

        vector<int> distance(n, INT_MAX);
        int src = topoOrder.top();
        topoOrder.pop();
        distance[src] = 0;

        for (auto nbr : adjList[0])
        {

            if (distance[0] + nbr.second < distance[nbr.first])
            {
                distance[nbr.first] = distance[0] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {

            int frontnode = topoOrder.top();
            topoOrder.pop();

            if (distance[frontnode] != INT_MAX)
            {
                for (auto nbr : adjList[frontnode])
                {
                    // nbr.second=edge ke upr wala distance
                    // nbr.first=purana distance
                    if (distance[frontnode] + nbr.second < distance[nbr.first])
                    {
                        distance[nbr.first] = distance[frontnode] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing ans:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << "->" << distance[i] << endl;
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

    // for topological sort
    unordered_map<int, bool> visited;
    stack<int> topoOrder;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topoSortDFS(0, visited, topoOrder);
        }
    }

    cout << "Printing Topological order" << endl;
    while (!topoOrder.empty())
    {
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }

    cout << endl;

    cout << "Printing Stack size: " << topoOrder.size() << endl;

    int destination = 3;

    // for shortest path using bfs
    g.shortestPathDFS(destination, topoOrder, n);

    return 0;
}