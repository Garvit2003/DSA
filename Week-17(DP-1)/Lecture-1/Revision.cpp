#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{

    // Base Case
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    // Recursive relation
    int ans = fib(n - 1) + fib(n - 2);

    return ans;
}

int topDown(vector<int> &dp, int n)
{
    // Base Case
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    // Check id ans already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Recursive relation
    dp[n] = topDown(dp, n - 1) + topDown(dp, n - 2);

    return dp[n];
}

int bottomUp(int n)
{

    // Step 1= Create dp array
    vector<int> dp(n + 1, -1);

    // Step 2= observe base case in above solution
    dp[0] = 0;
    dp[1] = 1;
    if (n == 0)
    {
        return dp[0];
    }

    // if (n == 2)
    // {
    //     return dp[1];
    // }

    // Step 3: Observe top down and write accordingly
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int spaceOptimisation(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    if (n == 0)
    {
        return prev2;
    }
    if (n == 1)
    {
        return prev1;
    }

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev1 = curr;
        prev2 = prev1;
    }
    return curr;
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    // vector<int> dp(n + 1, -1);

    // int ans = topDown(dp, n);

    // int ans = bottomUp(n);

    int ans = spaceOptimisation(n);

    cout << "Ans is " << ans << endl;
}