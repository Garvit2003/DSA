#include <iostream>
#include <vector>
using namespace std;

long long int MOD = 1000000007;

long long int solveUsingSO(long long int n, long long int k, long long int target)
{
    // step 1: create an array
    // vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, 0));
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    // base case
    prev[0] = 1;

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
                    recAns = prev[t - i];
                }
                recAns = recAns % MOD;
                ans = ans % MOD;
                ans = (recAns + ans) % MOD;
            }
            curr[t] = ans;
        }
        // shift
        prev = curr;
    }

    return prev[target];
}

int main()
{
    int n = 2;
    int k = 6;
    int target = 7;

    long long int ans = solveUsingSO(n, k, target);

    cout << "Answer is " << ans << endl;
}
