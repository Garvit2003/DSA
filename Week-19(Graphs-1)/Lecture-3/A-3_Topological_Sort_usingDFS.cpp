#include <iostream>
#include <stacks>
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

    void topoSortDFS(T src, unordered_map<int, bool> &visited, stack<int> &ans)
    {

        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
        // while returning store the node in stack
        ans.push(src);
    }
}

int
main()
{
    unordered_map<int, bool> visited;
    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.topoSortDFS(i, visited, ans);
        }
    }

    cout << "topo sort" << endl;
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
}
