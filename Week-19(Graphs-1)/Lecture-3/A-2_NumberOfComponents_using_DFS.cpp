#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    // how to add edge in a list
    void addEdge(T u, T v, bool direction)
    {
        // direction=0->undirected graph
        // direction=1->directed graph
        // create an edge from u to v
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
            for (auto neighbour : node.second)
            {
                cout << neighbour << ",";
            }
            cout << endl;
        }
    }

    int countConnectedComponents()
    {
        unordered_map<int, bool> visited;
        int count = 0;
        for (auto node : adjList)
        {
            if (!visited[node.first])
            {
                bfs(node.first, visited);
                count++;
            }
        }
        return count;
    }

    void bfs(T src, unordered_map<int, bool> &visited)
    {
        queue<T> q;

        // source node ko queue mein push kr diya
        q.push(src);
        // aur fir usse true mark kr diya visited wale map mein
        visited[src] = true;

        // loop tab tak chalega jab tak queue empty ni ho jati
        while (!q.empty())
        {
            // step 1L frontnode nikalo
            int frontnode = q.front();
            // step 2:frontnode ko pop kro
            q.pop();
            // step 3:Print frontnode
            cout << frontnode << ",";

            // step 4:insert neighbours
            for (auto neighbour : adjList[frontnode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<int, bool> &visited2)
    {
        cout << src << ",";
        visited2[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited2[neighbour])
            {
                dfs(neighbour, visited2);
            }
        }
    }
};

int main()
{

    Graph<int> g;
    int n = 8;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(3, 7, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(7, 4, 0);
    g.printAdjacencyList();
    cout << endl;

    // creating a map for visited nodes
    unordered_map<int, bool> visited;
    cout << "Printing BFS Traversal: " << endl;
    // run a loop for all nodes or bcz graph disconnected hai so different different sources ke liye call bhejni hi padegi
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }
    cout << endl;

    // creating a map for visited nodes
    unordered_map<int, bool> visited2;
    cout << "Printing DFS Traversal: " << endl;
    // run a loop for all nodes or bcz graph disconnected hai so different different sources ke liye call bhejni hi padegi
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }

    cout << endl;

    int componentCount = g.countConnectedComponents();
    cout << endl;
    cout << "Number of connected components: " << componentCount << endl;

    return 0;
}