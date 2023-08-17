#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    int ans = solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2);

    return ans;
}

int solveUsingMemoisation(int n, vector<int> &dp)
{
    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2);

    return dp[n];
}

int solveUsingTabulation(int n)
{

    vector<int> dp(n + 1, 0);

    // base case
    if (n == 0)
    {
        return dp[0];
    }

    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int solveUsingSO(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n = 5;

    int ans = solveUsingSO(n);

    cout << ans << endl;

    return 0;
}