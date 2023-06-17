#include <iostream>
#include <vector>
using namespace std;

int solveUsingTab(int n, int k)
{

    // Step 1: Create dp array
    vector<int> dp(n + 1, 0);

    // Step 2:Base case
    dp[1] = k;
    dp[2] = (k + k * (k - 1));

    // Step 3
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) * (k - 1);
    }
    return dp[n];
}

int main()
{
    int n = 4;
    int k = 3;

    int ans = solveUsingTab(n, k);
    cout << "Answer is: " << ans << endl;
}