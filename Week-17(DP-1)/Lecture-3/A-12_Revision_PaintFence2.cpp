#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int n, int k)
{
    // Step 1: solve using recursion
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    // step 2: Recursive relation
    int ans = (solveUsingRecursion(n - 1, k) + solveUsingRecursion(n - 2, k)) * (k - 1);
    return ans;
}

int solveUsingMemoisation(int n, int k, vector<int> &dp)
{
    // Step 1: solve using recursion
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    // Step 3: Check if ans already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step 2: store ans in dp
    dp[n] = (solveUsingRecursion(n - 1, k) + solveUsingRecursion(n - 2, k)) * (k - 1);
    return dp[n];
}

int solveUsingTabulation(int n, int k)
{
    // Step 1: Create dp array
    vector<int> dp(n + 1, 0);

    // step 2: base case
    dp[1] = k;
    dp[2] = k + k * (k - 1);

    // step 3: observation
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}

int solveUsingSO(int n, int k)
{
    int prev2 = k;
    int prev1 = k + k * (k - 1);
    int curr = 0;

    // step 3: observation
    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    int n = 4;
    int k = 3;

    int ans = solveUsingSO(n, k);
    cout << ans << endl;
    return 0;
}