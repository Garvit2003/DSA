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
            // The code checks if the current node node.first has not been visited yet. The first node encountered in the loop is node 0.
            if (!visited[node.first])
            {
                // The bfs() function is called with the current node (0) and the visited map as parameters. It will start a BFS traversal from node 0, marking all the nodes reachable from 0 as visited.
                bfs(node.first, visited);
                // The BFS traversal starts from node 0 and explores its neighboring nodes. Node 0 is connected to nodes 1 and 2. So, during the BFS, nodes 1 and 2 are marked as visited.

                count++;
            }
            // After the BFS traversal from node 0 is complete, one connected component has been found (nodes 0, 1, and 2 are part of it). Therefore, the count is incremented from 0 to 1.

            // Next Iteration:
            // The loop continues to the next node in the adjList, which is node 3. However, node 3 is not connected to nodes 0, 1, or 2. Since it is unvisited, the function enters another BFS from node 3.

            // BFS from Node 3:
            // The BFS traversal from node 3 doesn't find any neighboring nodes because it is not connected to any other nodes. Thus, only node 3 is marked as visited.
        }
        return count;
    }

    bool bfs(T src, unordered_map<int, bool> &visited)
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

    int componentCount = g.countConnectedComponents();
    cout << endl;
    cout << "Number of connected components: " << componentCount << endl;

    return 0;
}