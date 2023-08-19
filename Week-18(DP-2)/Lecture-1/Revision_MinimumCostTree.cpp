#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // base case
    if (left == right)
    {
        return 0;
    }
    // recursive relation
    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solveUsingRecursion(arr, maxi, left, i) + solveUsingRecursion(arr, maxi, i + 1, right));
    }
    return ans;
}

int solveUsingMemoisation(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
{
    // base case
    if (left == right)
    {
        return 0;
    }

    // Step 3: Check if ans already exists
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    // recursive relation
    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solveUsingMemoisation(arr, maxi, left, i, dp) + solveUsingMemoisation(arr, maxi, i + 1, right, dp));
    }

    // Step 2: store ans in dp
    dp[left][right] = ans;
    return dp[left][right];
}

int solveUsingTabulation(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    int n = arr.size();

    // Step 1: Create dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int left = n - 1; left >= 0; left--)
    {
        for (int right = 0; right <= n - 1; right++)
        {
            if (left >= right)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                for (int i = left; i < right; i++)
                {
                    ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    vector<int> arr{6, 2, 4};
    map<pair<int, int>, int> maxi;

    // pre computation
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
        }
    }

    int n = arr.size();

    int ans = solveUsingTabulation(arr, maxi, 0, n - 1);
    cout << ans << endl;

    return 0;
}