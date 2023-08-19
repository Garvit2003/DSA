#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solveUsingTab(int start, int end)
{

    int n = 10;

    // Step 1: Create dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int start = n; start >= 1; start--)
    {
        for (int end = 1; end <= n; end++)
        {
            if (start >= end)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                for (int i = start; i <= end; i++)
                {
                    ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
                dp[start][end] = ans;
            }
        }
    }
    return dp[1][n];
}

int main()
{
    int start = 1;
    int end = 10;

    int ans = solveUsingTab(start, end);
    cout << ans << endl;
}