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

    for (int i = 0; i < e; i++) /* i<e bcz jitne edge honge utne hi to inpur daalne honge */
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (source destination): ";
        cin >> u >> v;
        adj[u][v] = 1;
        // adj[v][u] = 1; // Assuming an undirected graph
    }

    cout << "Adjacency matrix representation:" << endl;
    // i<n bcz jitne node hai utne hi toh representation hai matrix ki
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
