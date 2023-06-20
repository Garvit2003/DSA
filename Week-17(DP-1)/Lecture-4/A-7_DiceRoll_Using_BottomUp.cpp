#include <iostream>
#include <vector>
using namespace std;

long long int MOD = 1000000007;

long long int solveUsingTab(long long int n, long long int k, long long int target)
{
    // step 1: create an array
    vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, 0));

    // base case
    dp[0][0] = 1;

    for (int index = 1; index <= n; index++)
    {
        for (int t = 1; t <= target; t++)
        {

            long long int ans = 0;
            for (int i = 0; i <= k; i++)
            {
                long long int recAns = 0;
                if (t - i >= 0)
                {
                    recAns = solveUsingTab(index - 1, k, t - i);
                }
                recAns = recAns % MOD;
                ans = ans % MOD;
                ans = (recAns + ans) % MOD;
            }
            dp[index][t] = ans;
        }
    }

    return dp[n][target];
}

int main()
{
    int n = 2;
    int k = 6;
    int target = 7;

    long long int ans = solveUsingTab(n, k, target);

    cout << "Answer is " << ans << endl;
}
