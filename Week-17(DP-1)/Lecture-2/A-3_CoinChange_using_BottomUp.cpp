#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int coinChange(int amount, vector<int> coins)
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

    // recursive relation
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = coinChange(amount - coins[i], coins);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

int topDown(int amount, vector<int> coins, vector<int> &dp)
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

    // step-3 check if ans already exists
    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    int n = coins.size();

    // recursive relation
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = topDown(amount - coins[i], coins, dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    dp[amount] = mini;
    return dp[amount];
}

int bottomUp(int amount, vector<int> coins)
{

    // step-1: Create dp array
    vector<int> dp(amount + 1, INT_MAX);

    // step-2: base case dekho
    if (amount == 0)
    {
        dp[0] = 0;
    }

    // step-3:follow the top down approach and write accordingly201
    for (int target = 0; target <= amount; target++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = dp[target - coins[i]];
            if (ans != INT_MAX)
            {
                mini = min(mini, ans + 1);
            }
        }
        dp[target] = mini;
    }
    return dp[amount];
}

int main()
{
    int amount;
    cout << "Enter the value of amount: " << endl;
    cin >> amount;

    vector<int> coins{1, 2};

    // step-1 create dp array
    // vector<int> dp{amount + 1, -1};

    int ans = bottomUp(amount, coins);
    cout << "The no. of coins required are: " << ans << endl;

    return 0;
}