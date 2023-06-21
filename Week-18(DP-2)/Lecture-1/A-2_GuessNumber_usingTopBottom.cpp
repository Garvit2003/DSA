#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solveUsingMem(int start, int end, vector<vector<int>> &dp)
{
    // Base case
    if (start >= end)
    {
        return 0;
    }

    // Step 3: Check if ans already exists
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveUsingMem(start, i - 1, dp), solveUsingMem(i + 1, end, dp)));
    }

    // Step 3: Store ans in dp array
    dp[start][end] = ans;
    return dp[start][end];
}

int main()
{
    int start = 1;
    int end = 10;

    // Step 1: Create dp array
    vector<vector<int>> dp(11, vector<int>(11, -1));

    int ans = solveUsingMem(start, end, dp);
    cout << ans << endl;
}