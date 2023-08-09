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

    void floyd_warshall(int n)
    {
        vector<vector<int>> distance(n, vector<int>(n, 1e9));

        // diagonal pr 0 mark krdo
        for (int i = 0; i < n; i++)
        {
            distance[i][i] = 0;
        }

        // graph ke according distance insert krdia hai
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                distance[u][v] = wt;
            }
        }

        // updation start
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int des = 0; des < n; des++)
                {
                    distance[src][des] = min(distance[src][des], distance[src][helper] + distance[helper][des]);
                }
            }
        }

        cout << "Printing distance array: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << distance[i][j] << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph<int> g;

    g.addEdge(0, 1, 3, 0);
    g.addEdge(0, 3, 5, 0);
    g.addEdge(1, 0, 2, 0);
    g.addEdge(1, 3, 4, 0);
    g.addEdge(2, 1, 1, 0);
    g.addEdge(3, 2, 2, 0);

    g.printAdjList();

    g.floyd_warshall(4);
}