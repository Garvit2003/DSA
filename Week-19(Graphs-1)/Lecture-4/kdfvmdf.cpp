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

    return 0;
}