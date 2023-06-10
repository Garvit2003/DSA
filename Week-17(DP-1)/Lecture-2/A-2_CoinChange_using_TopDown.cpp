#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int topDown(vector<int> &coins, int amount, vector<int> &dp)
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
    // step3:ans already exists
    if (dp[amount] != -1)
        return dp[amount];

    // recursive relation
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = topDown(coins, amount - coins[i], dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }

    // step-2:ans store in dp array
    dp[amount] = mini;
    return dp[amount];
}

int main()
{
    vector<int> coins{1, 2};
    int amount = 5;

    // step1:create dp array
    vector<int> dp{amount + 1, -1};

    int ans = topDown(coins, amount, dp);

    // if (ans == INT_MAX)
    //     return -1;
    // else
    cout << "Answer is: " << ans << endl;
}