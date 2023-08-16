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

        set<pair<int, int>> st;
        vector<int> dis(n, INT_MAX);

        dis[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            auto topElement = *(st.begin());

            int nodedistance = topElement.first;
            int node = topElement.second;

            // yhii pr glti hogi
            st.erase(st.begin());

            // nbr traverse
            for (auto nbr : adjList[node])
            {

                if (nodedistance + nbr.second < dis[nbr.first])
                {
                    auto result = st.find(make_pair(dis[nbr.first], nbr.first));
                    if (result != st.end())
                    {
                        st.erase(result);
                    }

                    dis[nbr.first] = nodedistance + nbr.second;
                    st.insert(make_pair(dis[nbr.first], nbr.first));
                }
            }
        }
        cout << "Printing ans: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dis[i] << ",";
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
