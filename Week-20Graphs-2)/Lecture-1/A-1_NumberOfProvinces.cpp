#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int src, unordered_map<int, bool> &visited, vector<vector<int>> &isConnected)
{
    visited[src] = true;

    // row -source
    // column- we will run a loop
    // for (int i = 0; i < isConnected.size(); i++)
    // {
    //     if (isConnected[src][i] == 1 && !visited[i])
    //     {
    //         dfs(i, visited, isConnected);
    //     }
    // }

    for (int i = 0; i < isConnected.size(); i++)
    {
        if (isConnected[src][i] == 1 && src != i)
        {
            if (!visited[i])
            {
                dfs(i, visited, isConnected);
            }
        }
        {
        }
    }
}

int findProvince(vector<vector<int>> &isConnected)
{
    unordered_map<int, bool> visited;
    int count = 0;
    int n = isConnected.size();

    // i represents node here
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, isConnected);
            count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1},
    };

    int result = findProvince(isConnected);
    cout << "No. of provinces are " << result;
}