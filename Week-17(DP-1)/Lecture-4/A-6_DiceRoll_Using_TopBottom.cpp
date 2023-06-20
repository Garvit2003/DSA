#include <iostream>
#include <vector>
using namespace std;

long long int MOD = 1000000007;

long long int solveUsingMem(long long int n, long long int k, long long int target, vector<vector<long long int>> dp)
{

    // base case
    if (n < 0)
    {
        return 0;
    }

    if (n == 0 && target == 0)
    {
        return 1;
    }

    if (n == 0 && target != 0)
    {
        return 0;
    }

    if (n != 0 && target == 0)
    {
        return 0;
    }

    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    long long int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        long long int recAns = 0;
        if (target - i >= 0)
        {
            recAns = solveUsingMem(n - 1, k, target - i, dp);
        }
        recAns = recAns % MOD;
        ans = ans % MOD;
        ans = (recAns + ans) % MOD;
    }
    dp[n][target] = ans;
    return dp[n][target];
}

int main()
{
    int n = 2;
    int k = 6;
    int target = 7;

    // step 1: create an array
    vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));

    long long int ans = solveUsingMem(n, k, target, dp);

    cout << "Answer is " << ans << endl;
}
