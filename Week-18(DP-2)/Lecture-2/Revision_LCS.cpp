#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(string a, string b, int i, int j)
{
    if (i == a.length())
    {
        return 0;
    }
    if (j == b.length())
    {
        return 0;
    }

    if (a[i] == b[j])
    {
        return 1 + solveUsingRecursion(a, b, i + 1, j + 1);
    }

    else
    {
        return max(solveUsingRecursion(a, b, i + 1, j), solveUsingRecursion(a, b, i, j + 1));
    }
}

int solveUsingMemoisation(string a, string b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length())
    {
        return 0;
    }
    if (j == b.length())
    {
        return 0;
    }

    // Step 3: Check if ans already exists
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;

    if (a[i] == b[j])
    {
        ans = 1 + solveUsingMemoisation(a, b, i + 1, j + 1, dp);
    }

    else
    {
        ans = max(solveUsingMemoisation(a, b, i + 1, j, dp), solveUsingMemoisation(a, b, i, j + 1, dp));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int solveUsingTabulation(string a, string b, int i, int j)
{

    // Step 1: Create dp array
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;

            if (a[i] == b[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }

            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int solveUsingSO(string a, string b, int i, int j)
{

    // Step 1: Create dp array
    vector<int> next(b.length() + 1, 0);
    vector<int> curr(a.length() + 1, 0);

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;

            if (a[i] == b[j])
            {
                ans = 1 + next[j + 1];
            }

            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }

    return curr[0];
}

int solveUsingSO2(string a, string b, int i, int j)
{

    // Step 1: Create dp array
    // vector<int> next(b.length() + 1, 0);
    vector<int> curr(b.length() + 1, 0);

    for (int i = a.length() - 1; i >= 0; i--)
    {
        for (int j = b.length() - 1; j >= 0; j--)
        {
            int ans = 0;

            if (a[i] == b[j])
            {
                ans = 1 + curr[j + 1];
            }

            else
            {
                ans = max(curr[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
    }

    return curr[0];
}

int main()
{
    string a = "abc";
    string b = "abcde";

    int i = 0;
    int j = 0;

    int ans = solveUsingSO2(a, b, i, j);
    cout << ans;
    return 0;
}