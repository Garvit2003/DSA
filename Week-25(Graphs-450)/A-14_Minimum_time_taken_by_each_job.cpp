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
        if (direction == 0)
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

    int minimumTime(int n, vector<int> &ans)
    {
        // vector<int> job{n, INT_MAX};

        queue<pair<int, int>> q;
        unordered_map<int, int> inDegree;

        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                inDegree[nbr]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push({i, 1});
                // job[i] = 1;
            }
        }
        int ansTime = 0;

        while (!q.empty())
        {
            auto frontnode = q.front();
            int time = frontnode.second;
            int node = frontnode.first;
            q.pop();

            // ans.push_back(node);

            for (auto nbr : adjList[node])
            {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                {
                    ansTime = max(ansTime, time + 1);
                    q.push({nbr, time + 1});
                    // job[nbr] = job[frontnode] + 1;
                }
            }
        }

        return ansTime;

        // for (int i = 0; i < n; i++)
        // {
        //     cout << job[i] << " ";
        // }
        // cout << endl;
    }
};

int main()
{
    graph<int> g;

    // Given Nodes n and edges m
    int n = 10;

    // Given Directed Edges of graph
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(1, 5, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 8, 1);
    g.addEdge(2, 9, 1);
    g.addEdge(3, 6, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(4, 8, 1);
    g.addEdge(5, 8, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 1);
    g.addEdge(8, 10, 1);

    g.printAdjList();
    cout << endl;

    vector<int> ans;

    // Function Call
    g.minimumTime(n, ans);

    // while (!ans.empty())
    // {
    //     cout << ans.top() << " ";
    //     ans.pop();
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // for (auto i : ans)
    // {
    //     cout << i << ",";
    // }
    // cout << endl;

    return 0;
}