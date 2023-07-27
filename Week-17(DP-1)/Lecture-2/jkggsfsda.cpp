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

int main()
{
    int amount;
    cout << "Enter the value of amount: " << endl;
    cin >> amount;

    vector<int> coins{1, 2};

    int ans = coinChange(amount, coins);
    cout << "The no. of coins required are: " << ans << endl;

    return 0;
}