#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(vector<int> &coins, int amount)
{

    // base case
    if (amount == 0)
    {
        return 0;
    }

    if (amount < 0)
    {
        return INT_MAX;
    }

    int n = coins.size();

    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int ans = solveUsingRecursion(coins, amount - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

int solveUsingMemiosation(vector<int> &coins, int amount, vector<int> &dp)
{

    // base case
    if (amount == 0)
    {
        return 0;
    }

    if (amount < 0)
    {
        return INT_MAX;
    }

    // step3: Check if ans already exists
    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    int n = coins.size();
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int ans = solveUsingMemiosation(coins, amount - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }

    // step2:store ans in dp
    dp[amount] = mini;
    return mini;
    // return dp[amount];
}

int solveUsingTabulation(vector<int> &coins, int amount)
{

    // Step 1:Create dp array
    vector<int> dp(amount + 1, INT_MAX);

    // step 2: base case

    dp[0] = 0;

    int n = coins.size();

    for (int target = 1; target <= amount; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (target - coins[i] >= 0)
            {
                int ans = dp[target - coins[i]];
                if (ans != INT_MAX)
                {
                    mini = min(mini, (ans + 1));
                }
            }
        }
        dp[target] = mini;
    }
    return dp[amount];
}

int main()
{
    vector<int> coins{1, 2};
    int amount = 5;

    int ans = solveUsingTabulation(coins, amount);
    cout << ans;
    return 0;
}