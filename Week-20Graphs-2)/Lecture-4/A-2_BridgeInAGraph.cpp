#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 1)
        {
            adjList[v].push_back(u);
        }
    }

    void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto nbr : adjList[src])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!visited[nbr])
            {
                // dfs call
                findBridges(nbr, src, timer, tin, low, visited);

                // low update
                low[src] = min(low[src], low[nbr]);

                // check for bridge
                if (low[nbr] > tin[src])
                {
                    cout << nbr << "--" << src << " is a bridge." << endl;
                }
            }
            else
            {
                // node is visited or not a parent
                // low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
};

int main()
{
    graph<int> g;

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(3, 4, 1);

    int n = 5;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int, bool> visited;

    g.findBridges(0, -1, timer, tin, low, visited);
}