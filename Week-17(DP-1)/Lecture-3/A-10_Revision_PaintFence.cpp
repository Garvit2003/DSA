#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recursiveSolution(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    int ans = (recursiveSolution(n - 1, k) + recursiveSolution(n - 2, k)) * (k - 1);
    return ans;
}

int topdown(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return (k + k * (k - 1));
    }

    // step 3: Check if ans already exists

    dp[n] = (topdown(n - 1, k, dp) + topdown(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

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

int spaceOptimisation(int n, int k)
{
    int prev2 = k;
    int xprev1 = k + k * (k - 1);

    for (int i = 3; i <= n; i++)
    {
        int curr = (prev1 + prev2) * (k - 1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cout << "Enter the no. of fence: " << endl;
    cin >> n;

    int k;
    cout << "Enter the no. of colours: " << endl;
    cin >> k;

    // step 1 create dp array
    // vector<int> dp(n + 1, -1);

    int ans = spaceOptimisation(n, k);

    cout << "Answer is: " << ans << endl;
    return 0;
}