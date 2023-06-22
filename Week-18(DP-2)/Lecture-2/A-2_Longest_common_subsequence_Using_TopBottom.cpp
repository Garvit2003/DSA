#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingMem(string a, string b, int i, int j, vector<vector<int>> &dp)
{
    // if (i == a.size())
    // {
    //     return 0;
    // }

    // if (j == b.size())
    // {
    //     return 0;
    // }

    if (i == a.size() || j == b.size())
    {
        return 0;
    }

    // Step 3:Check if ans already exists
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // Method 1
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        ans = max(solveUsingMem(a, b, i + 1, j, dp), solveUsingMem(a, b, i, j + 1, dp));
    }

    // Step 2: Store ans in dp array
    dp[i][j] = ans;
    return dp[i][j];

    // Method 2
    // if (a[i] == b[j])
    // {
    //     return 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
    // }
    // else
    // {
    //     return max(solveUsingMem(a, b, i + 1, j, dp), solveUsingMem(a, b, i, j + 1, dp));
    // }
}

int main()
{
    string a = "abc";
    string b = "abcde";

    int i = 0;
    int j = 0;

    // Step 1: Create dp array
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));

    int ans = solveUsingMem(a, b, i, j, dp);
    cout << "Answer is: " << ans << endl;
}