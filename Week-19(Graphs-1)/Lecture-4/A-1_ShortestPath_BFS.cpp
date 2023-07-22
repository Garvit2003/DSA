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

    void shortestPathBFS(int src, int destination)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial steps
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();

            for (auto nbr : adjList[frontnode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = frontnode;
                }
            }
        }

        // store path in ans after traversing in the parent array
        vector<int> ans;
        int node = destination;

        // 1- Initially, node is set to the destination node (the node for which we want to find the shortest path).
        // 2- We look up the value of parent[node], which gives us the parent node of the current node. This parent node is the node that was visited just before the current node during the BFS traversal.
        // 3- We update the value of node to be equal to its parent node. This effectively moves us one step closer to the source node.
        // 4- We repeat steps 2 and 3 until we reach the source node (where the parent is -1).
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout << "Printing ans" << endl;
        for (auto i : ans)
        {
            cout << i << ",";
        }
        cout << endl;
    }
};

int main()
{
    graph<int> g;

    g.addEdge(0, 1, 1, 0);
    g.addEdge(1, 2, 1, 0);
    g.addEdge(2, 3, 1, 0);
    g.addEdge(3, 4, 1, 0);

    g.addEdge(0, 5, 1, 0);
    g.addEdge(5, 4, 1, 0);

    g.addEdge(0, 6, 1, 0);
    g.addEdge(6, 7, 1, 0);
    g.addEdge(7, 8, 1, 0);
    g.addEdge(8, 4, 1, 0);

    g.printAdjList();

    int src = 0;
    int destination = 4;

    g.shortestPathBFS(src, destination);

    return 0;
}