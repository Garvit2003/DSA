#include <iostream>
#include <stack>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    // Adding edge
    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
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

    void dfs(T src, unordered_map<int, bool> &visited)
    {
        cout << src << ",";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }

    // void topoSortDFS(T src, unordered_map<int, bool> &visited, stack<int> &ans)
    // {

    //     visited[src] = true;

    //     for (auto neighbour : adjList[src])
    //     {
    //         if (!visited[neighbour])
    //         {
    //             topoSortDFS(neighbour, visited, ans);
    //         }
    //     }
    //     // while returning store the node in stack
    //     cout << "Storing " << src << "in stack" << endl;
    //     ans.push(src);
    // }

    void topoSortBFS(int n, vector<int> &ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;

        // indegree calculate
        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // put all nodes inside queue, which has indegree=0
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // bfs logic

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();

            ans.push_back(frontnode);

            // indegree ke liye solve
            for (auto nbr : adjList[frontnode])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{

    Graph<int> g;
    int n = 8;
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(7, 0, 1);
    g.addEdge(7, 1, 1);

    g.printAdjacencyList();
    cout << endl;

    vector<int> ans;

    // connected or disconnected
    g.topoSortBFS(n, ans);

    cout << "Printing topological Sort using BFS" << endl;

    for (auto i : ans)
    {
        cout << i << ",";
    }
    cout << endl;

    // unordered_map<int, bool> visited;
    // stack<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         g.topoSortDFS(i, visited, ans);
    //     }
    // }

    // cout << "Topological sort" << endl;
    // while (!ans.empty())
    // {
    //     cout << ans.top();
    //     ans.pop();
    // }
}
