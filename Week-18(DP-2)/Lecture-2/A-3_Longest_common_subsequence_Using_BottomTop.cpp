#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingTab(string a, string b, int i, int j)
{

    // Step 1: Create dp array
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int main()
{
    string a = "abc";
    string b = "abcde";

    int i = 0;
    int j = 0;

    int ans = solveUsingTab(a, b, i, j);
    cout << "Answer is: " << ans << endl;
}