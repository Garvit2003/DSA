#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <list>
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
        vector<int> dis(n, INT_MAX);
        set<pair<int, int>> st;
        // initial steps
        dis[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // set ko iterator se access krte hai, index se ni
            // st.begin= iterator
            // actual value= *(st.begin()) , *=rereference operator
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop the element from set
            st.erase(st.begin());

            // neighbour traverse

            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < dis[nbr.first])
                {
                    // mujhe distance update krna hai set mein bhi aur distance wale array mein bhi. usse liye mujhe pehle ye check krna padega ki set mein wo distance hai ya nhii or simply search krna padega set mein
                    // basicall muje wo distance chahiye hogi update krne ke liye toh main us distance ko pehle dudhunga.

                    // finding entry in set
                    // purani entry ko search kra set mein
                    auto result = st.find(make_pair(dis[nbr.first], nbr.first));

                    // if found then remove
                    // purani entry ko remove kra set se
                    if (result != st.end())
                    {
                        st.erase(result);
                    }

                    // Updating distance in distance array
                    dis[nbr.first] = nodeDistance + nbr.second;

                    // nyii entry ko insert kr diya
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

    g.shortestDisDijkstra(6, 7);

    return 0;
}