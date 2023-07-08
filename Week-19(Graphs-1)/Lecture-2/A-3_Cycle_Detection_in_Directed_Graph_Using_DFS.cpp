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

    // FOR BFS
    bool checkCyclicUsingBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            for (auto nbr : adjList[frontnode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontnode;
                }
                else
                {
                    // already visited
                    if (nbr != parent[frontnode])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // FOR DFS
    bool checkCyclicUsingDFS(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool checkaageKaAns = checkCyclicUsingDFS(nbr, visited, src);
                if (checkaageKaAns == true)
                {
                    return true;
                }
            }
            if (visited[nbr] && nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool checkCyclicDirectedGraphUsingDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAns = checkCyclicDirectedGraphUsingDFS(nbr, visited, dfsVisited);
                if (aageKaAns == true)
                {
                    return true;
                }
            }
            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }
        // YHII PR GLTI HOGI
        /* Here is the explanation for the code above:
1. We are marking all the vertices as false i.e. unvisited.
2. We will mark the vertex visited and push it into the stack.
3. While the stack is not empty, we will pop the top element.
4. We will print the element and mark it as visited.
5. We will visit all the adjacent elements of the current element.
   If any of the adjacent element is unvisited, we will push it into the stack.
   If all the adjacent elements are visited, we will pop the element from the stack.
6. We will repeat the process until the stack is empty. */

        dfsVisited[src] = false;
        return false;
    }
};

int main()
{

    Graph<int> g;
    int n = 5;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 0, 1);
    g.printAdjacencyList();
    cout << endl;

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicDirectedGraphUsingDFS(i, visited, dfsVisited);
            if (ans == true)
            {
                break;
            }
        }
    }
    if (ans == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is absent" << endl;
    }

    // // For BFS
    // bool ans = false;
    // unordered_map<int, bool> visited;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans = g.checkCyclicUsingBFS(i, visited);
    //         if (ans == true)
    //         {
    //             break;
    //         }
    //     }
    // }

    // cout << "Printing for BFS traversal" << endl;
    // if (ans == true)
    // {
    //     cout << "Cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "Cycle is absent" << endl;
    // }

    // // for DFS

    // bool ansDFS = false;
    // unordered_map<int, bool> visitedDFS;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visitedDFS[i])
    //     {
    //         ans = g.checkCyclicUsingDFS(i, visitedDFS, -1);
    //         if (ansDFS == true)
    //         {
    //             break;
    //         }
    //     }
    // }
    // cout << "Printing for BFS traversal" << endl;
    // if (ansDFS == true)
    // {
    //     cout << "Cycle is present" << endl;
    // }
    // else
    // {
    //     cout << "Cycle is absent" << endl;
    // }
}