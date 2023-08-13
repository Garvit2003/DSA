#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
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
        if (direction == 1)
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

    void shortestDisDijkstra(int src, int n)
    {
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0, src));
        distance[src] = 0;

        while (!pq.empty())
        {
            int nodeDistance = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < distance[nbr.first])
                {
                    distance[nbr.first] = nodeDistance + nbr.second;
                    pq.push(make_pair(distance[nbr.first], nbr.first));
                }
            }
        }

        cout << "Printing Ans: " << endl;
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
    int n = 3;

    g.addEdge(6, 3, 2, 1);
    g.addEdge(6, 1, 14, 1);
    g.addEdge(3, 1, 9, 1);
    g.addEdge(3, 2, 10, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(2, 4, 15, 1);
    g.addEdge(4, 3, 11, 1);
    g.addEdge(6, 5, 9, 1);
    g.addEdge(4, 5, 6, 1);

    g.printAdjList();

    g.shortestDisDijkstra(6, 7);

    return 0;
}
