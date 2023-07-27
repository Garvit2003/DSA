#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Graph
{
public:
    int V;
    vector<vector<pair<int, int>>> adjList;

    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    void dijkstraAlgo(int src)
    {
        vector<int> distance(V, numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto nbr : adjList[u])
            {
                int v = nbr.first;
                int weight = nbr.second;

                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        cout << "Shortest Path Distances from Node " << src << ":\n";
        for (int i = 0; i < V; ++i)
        {
            cout << "Node " << i << ": " << distance[i] << endl;
        }
    }
};

int main()
{
    int n = 5; // Number of nodes in the graph
    Graph g(n);

    // Adding edges to the graph (node, node, weight)
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(2, 4, 6);
    g.addEdge(4, 3, 1);

    int source = 0;
    g.dijkstraAlgo(source);

    return 0;
}
