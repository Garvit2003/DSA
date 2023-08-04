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

    void topoSortDFS(unordered_map<int, bool> &visited, int src, stack<int> &topoOrder)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                topoSortDFS(visited, nbr, topoOrder);
            }
        }
        topoOrder.push(src);
    }

    void dfs2(int src, unordered_map<int, bool> &visited2, unordered_map<int, list<int>> adjNew)
    {
        visited2[src] = true;

        for (auto nbr : adjNew[src])
        {
            if (!visited2[nbr])
            {
                dfs2(nbr, visited2, adjNew);
            }
        }
    }

    int countSCC(int n)
    {
        stack<int> topoOrder;
        unordered_map<int, bool> visited;

        // Find topo Ordering
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                topoSortDFS(visited, i, topoOrder);
            }
        }

        // cout << "Printing Topoorder: " << endl;
        // while (!topoOrder.empty())
        // {
        //     cout << topoOrder.top() << ",";
        //     topoOrder.pop();
        // }
        // cout << endl;

        // agr hum yhaa order print krte hai toh scc 0 aata hai bcz print krte waqt hum topoOrder wale stack ko empty kr de rhee hai toh usse hmme stack hi empty mil rha hai first step mein so reverse aur dfs traverse ek empty stack pr ho rha hai isliye ans 0 hai.

        // Reverse all edges
        unordered_map<int, list<int>> adjNew;

        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                // pehle edge u se v hai
                int u = t.first;
                int v = nbr;

                // v->u insert ie reverse the edge
                adjNew[v].push_back(u);
            }
        }

        // traverse using dfs
        int count = 0;
        unordered_map<int, bool> visited2;

        while (!topoOrder.empty())
        {
            int node = topoOrder.top();
            topoOrder.pop();

            if (!visited2[node])
            {
                dfs2(node, visited2, adjNew);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    graph<int> g;
    int n = 8;

    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 0, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 6, 0);
    g.addEdge(6, 4, 0);
    g.addEdge(6, 7, 0);

    g.printAdjList();

    int ans = g.countSCC(n);
    cout << "Number of SCC: " << ans << endl;

    cout << endl;
}