#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(map<pair<int, int>, bool> &visited, int row, int col, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;

    q.push({row, col});
    visited[{row, col}] = true;

    while (!q.empty())
    {
        pair<int, int> frontnode = q.front();
        q.pop();
        int x = frontnode.first;
        int y = frontnode.second;

        // i can move in 4 direction
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && !visited[{newX, newY}] && grid[newX][newY] == '1')
            {
                q.push({newX, newY});
                visited[{newX, newY}] = true;
            }
        }
    }
}

int main()
{

    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
    };

    map<pair<int, int>, bool> visited;
    int count = 0;
    for (int row = 0; row < grid.size(); row++)
    {
        // The loop should iterate from 0 to 4 because you are trying to move in four directions (up, right, down, left). Therefore, the loop bound should be 4, not n.
        for (int col = 0; col < 4; col++)
        {
            if (!visited[{row, col}] && grid[row][col] == '1')
            {
                bfs(visited, row, col, grid);
                count++;
            }
        }
    }
    cout << "No. of provinces are: " << count << endl;

    return 0;
}