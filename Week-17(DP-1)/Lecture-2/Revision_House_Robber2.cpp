#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(vector<int> &nums, int n)
{

    // Step 1:base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }

    // step 2: Recursive relation

    // include
    int include = solveUsingRecursion(nums, n - 2) + nums[n];
    int exclude = solveUsingRecursion(nums, n - 1) + 0;

    return max(include, exclude);
}

int solveUsingMemoisation(vector<int> &nums, int n, vector<int> &dp)
{

    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return nums[0];
    }

    // Step 3: check if ans already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // include
    int include = solveUsingRecursion(nums, n - 2) + nums[n];

    // exclude
    int exclude = solveUsingRecursion(nums, n - 1) + 0;

    // Step 2: store ans in dp
    dp[n] = max(include, exclude);
    return dp[n];
}

int solveUsingTabulation(vector<int> &nums, int n)
{
    // Step 1: create dp array
    vector<int> dp(n + 1, 0);

    // Step 2:base case
    dp[0] = nums[0];

    // Step 3:observe memoisation
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
        {
            temp = dp[i - 2];
        }
        int include = temp + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n];
}

int solveUsingTabulationusingTernaryOperator(vector<int> &nums, int n)
{
    // Step 1: create dp array
    vector<int> dp(n + 1, 0);

    // Step 2:base case
    dp[0] = nums[0];

    // Step 3:observe memoisation
    for (int i = 1; i <= n; i++)
    {
        int include = (i - 2 >= 0 ? dp[i - 2] : 0) + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n];
}

int solveUsingSO(vector<int> &nums, int n)
{
    int prev2 = 0;
    int prev1 = nums[0];

    int curr = 0;

    for (int i = 0; i <= n; i++)
    {
        int include = (i - 2 >= 0 ? prev2 : 0) + nums[i];
        int exclude = prev1 + 0;
        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int n = nums.size() - 1;

    int ans = solveUsingSO(nums, n);
    cout << ans;

    return 0;
}