#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int ans = INT_MAX;

    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveUsingRecursion(start, i - 1), solveUsingRecursion(i + 1, end)));
    }
    return ans;
}

int solveUsingMemoisation(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }

    // Step 3: Check if ans already exists
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;

    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveUsingMemoisation(start, i - 1, dp), solveUsingMemoisation(i + 1, end, dp)));
    }

    // Step-2: store ans in dp
    dp[start][end] = ans;
    return dp[start][end];
}

int solveUsingTabulation(int start, int end)
{

    int n = 10;

    // Step 1: Create dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Step 3: Observation
    for (int start = n; start >= 1; start--)
    {
        for (int end = 1; end <= n; end++)
        {
            if (start >= end)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }

    return dp[1][n];
}

int main()
{
    int start = 1;
    int end = 10;

    int ans = solveUsingTabulation(start, end);
    cout << ans;

    return 0;
}