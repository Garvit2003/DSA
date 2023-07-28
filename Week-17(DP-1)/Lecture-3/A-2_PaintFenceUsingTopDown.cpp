#include <iostream>
#include <vector>
using namespace std;

int solveUsingMem(int n, int k, vector<int> &dp)
{
    // Base case
    if (n == 1)
        return k;

    if (n == 2)
        return (k + k * (k - 1));
    // step 3: Check if ans already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }
    // step 2: Store ans in dp
    dp[n] = (solveUsingMem(n - 2, k, dp) + solveUsingMem(n - 1, k, dp)) * (k - 1);
    return dp[n];
}

int main()
{
    int n = 4;
    int k = 3;

    // Step 1: Create dp array
    vector<int> dp(n + 1, -1);
    int ans = solveUsingMem(n, k, dp);
    cout << "Answer is: " << ans << endl;
}