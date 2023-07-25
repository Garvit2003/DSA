#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;
template <typename T>

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int v, int u, int weight, bool direction)
    {
        adjList[u].push_back({v, weight});
        if (direction == 1)
        {
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";
            for (auto nbr : node.second)
            {
                cout << "(" << nbr.first << "," << nbr.second << "),";
            }
            cout << endl;
        }
    }

    void dijkstraAlgo(int src, int n)
    {
        vector<int> distance(n, INT_MAX);
        set<pair<int, int>> st;

        distance[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            int frontnode = *(st.begin());
            int nodeDistance = frontnode.first;
            int node = frontnode.second;

            st.erase(st.begin());

            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < distance[nbr.first])
                {

                    // purani entry ko dhundho
                    auto result = st.find(make_pair(distance[nbr.first], nbr.first));

                    // agr mil gyii toh delete kro
                    if (result != st.end())
                    {
                        st.erase(result);
                    }

                    // update the distance in array
                    distance[nbr.first] = nodeDistance + nbr.second;

                    // update the distance in set
                    st.insert(make_pair(distance[nbr.first], nbr.first));
                }
            }
        }
        cout << "Printing ans: " << endl;
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
    int n = 5;

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

    // g.dijkstraAlgo(6, 7);
    return 0;
}