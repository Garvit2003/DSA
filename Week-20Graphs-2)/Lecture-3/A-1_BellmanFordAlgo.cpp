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
        if (direction == 1)
        {
            adjList[v].push_back({u, weight});
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

    void bellmanFordAlgo(int n, int src)
    {
        vector<int> distance(n, INT_MAX);

        distance[src] = 0;

        // n-1 relaxation step
        for (int i = 0; i < n - 1; i++)
        {
            // for all edges
            for (auto t : adjList)
            {
                for (auto nbr : t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if (distance[u] != INT_MAX && distance[u] + wt < distance[v])
                    {
                        distance[v] = wt + distance[u];
                    }
                }
            }
        }

        // checking for negative cycle
        bool negativeCycle = false;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;

                if (distance[u] != INT_MAX && distance[u] + wt < distance[v])
                {
                    // distance[v] = wt + distance[u];
                    negativeCycle = true;
                }
            }
        }

        if (negativeCycle == true)
        {
            cout << "Negative Cycle is present" << endl;
        }
        else
        {
            cout << "Negative cycle is absent" << endl;
        }

        cout << "Printing distance array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << distance[i] << ",";
        }
        cout << endl;
    }
};

int main()
{
    graph<int> g;

    g.addEdge(0, 1, -1, 0);
    g.addEdge(0, 2, 4, 0);
    g.addEdge(1, 2, 3, 0);
    g.addEdge(1, 3, 2, 0);
    g.addEdge(1, 4, 2, 0);
    g.addEdge(3, 1, 1, 0);
    g.addEdge(3, 2, 5, 0);
    g.addEdge(4, 3, -3, 0);

    g.printAdjList();
    cout << endl;

    g.bellmanFordAlgo(5, 0);
}