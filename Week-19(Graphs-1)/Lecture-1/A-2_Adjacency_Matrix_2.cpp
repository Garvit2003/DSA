#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) /* i<e bcz jitne edge honge utne hi to input daalne honge */
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> u >> v;
        adj[u][v] = 1;
        // adj[v][u] = 1; // Assuming an undirected graph
    }

    cout << "Adjacency matrix representation:" << endl;
    // i<n bcz jitne node hai utne hi toh representation hai matrix ki
    // The loop iterates over the range of i from 0 to n-1 because the nodes in the adjacency matrix are typically represented using zero-based indexing, where the first node has an index of 0 and the last node has an index of n-1.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
