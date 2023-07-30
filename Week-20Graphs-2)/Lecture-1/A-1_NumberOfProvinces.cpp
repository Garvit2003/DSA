#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int src, unordered_map<int, bool> &visited, vector<vector<int>> &isConnected)
{
    visited[src] = true;

    // row -source
    // column- we will run a loop
    for (int col = 0; col < isConnected.size(); col++)
    {
        if (isConnected[src][col] == 1)
        // isConnected[src][col]==1 means agr col 1 hai toh wo nbr hai aur agr 0 hai toh wo nbr ni hai
        {
            if (!visited[col])
            {
                dfs(col, visited, isConnected);
            }
        }
    }
}

int main()
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1},
    };

    unordered_map<int, bool> visited;
    int count = 0;
    int n = isConnected.size();

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, isConnected);
            count++;
        }
        // cout << "No. of provinces are " << count<<endl;
    }
    cout << "No. of provinces are " << count << endl;
}