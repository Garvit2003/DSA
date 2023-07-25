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
        // yhii pr glti hogi
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

    void toposortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {

        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                toposortDFS(nbr.first, visited, ans);
                visited[nbr.first] = true;
            }
        }
        ans.push(src);
    }

    void shortestPathDFS(stack<int> ans, int n)
    {
        vector<int> distance(n, INT_MAX);
        int src = ans.top();
        ans.pop();
        distance[src] = 0;
        for (auto nbr : adjList[0])
        {
            if (distance[0] + nbr.second < nbr.first)
            {
                nbr.first = distance[0] + nbr.second;
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
                        nbr.first = distance[frontnode] + nbr.second;
                    }
                }
            }
        }

        cout << "Printing ans: " << endl;
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

    unordered_map<int, bool> visited;
    stack<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.toposortDFS(i, visited, ans);
        }
    }

    cout << "Printing Topological order: " << endl;

    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;

    // stack size will be zero because during the topological sort vertices are pushed in the stack in the order of their dependencies, and then they are popped from the stack to obtain the topological order.

    cout << "Printing Stack size: " << ans.size();

    g.shortestPathDFS(ans, n);

    return 0;
}