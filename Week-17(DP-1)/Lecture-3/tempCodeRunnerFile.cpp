int bottomUp(int n, int k)
{
    // Step 1: Create dp array
    vector<int> dp(n + 1, 0);

    // Step 2: see base case
    dp[1] = k;
    dp[2] = k + k * (k - 1);

    // step 3: Observe top down approach
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}