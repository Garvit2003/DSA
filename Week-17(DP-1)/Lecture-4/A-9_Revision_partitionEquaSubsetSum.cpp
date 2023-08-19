#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solveUsingRecursion(vector<int> &nums, int target, int index)
{
    // Step 1: Base case
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (index > nums.size())
    {
        return 0;
    }

    // Step 2: Recursive relation
    bool include = solveUsingRecursion(nums, target - nums[index], index + 1);
    bool exclude = solveUsingRecursion(nums, target, index + 1);

    return (include || exclude);
}

bool solveUsingMemoisation(vector<int> &nums, int target, int index, vector<vector<int>> &dp)
{
    if (target < 0)
    {
        return 0;
    }
    if (target == 0)
    {
        return 1;
    }
    if (index > nums.size())
    {
        return 0;
    }

    // Step 3: Check if ans already exists

    bool include = dp[index + 1][target - nums[index]];
    bool exclude = dp[index + 1][target];

    // Step 2: store ans in dp
    dp[index][target] = (include || exclude);
    return dp[index][target];
}

bool solveUsingTabulation(vector<int> &nums, int target, int index)
{

    // Step-1: Create dp array
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));

    // Step 2: Base case
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i][0] = 1;
    }

    // Step 3: Observation

    int n = nums.size();

    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
            {
                include = dp[index + 1][t - nums[index]];
            }
            bool exclude = dp[index + 1][t];
            dp[index][t] = (include || exclude);
        }
    }

    return dp[0][target];
}

bool solveUsingSO(vector<int> &nums, int target, int index)
{

    // Step-1: Create dp array
    vector<int> next(target + 1, 0);
    vector<int> curr(target + 1, 0);

    // Step 2: Base case
    for (int i = 0; i < nums.size(); i++)
    {
        next[0] = 1;
    }

    // Step 3: Observation

    int n = nums.size();

    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
            {
                include = next[t - nums[index]];
            }
            bool exclude = next[t];
            curr[t] = (include || exclude);
        }
        next = curr;
    }

    return curr[target];
}

bool solveUsingSO2(vector<int> &nums, int target, int index)
{

    // Step-1: Create dp array
    vector<int> curr(target + 1, 0);

    // Step 2: Base case
    for (int i = 0; i < nums.size(); i++)
    {
        curr[0] = 1;
    }

    // Step 3: Observation

    int n = nums.size();

    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = target; t >= 1; t--)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
            {
                include = curr[t - nums[index]];
            }
            bool exclude = curr[t];
            curr[t] = (include || exclude);
        }
    }

    return curr[target];
}

int main()
{
    vector<int> nums{2, 5, 10, 7};

    // finding sum of elements of nums
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // check if sum is odd
    if (sum & 1)
    {
        cout << "Equal subsets do no exist " << endl;
    }

    int index = 0;
    int target = sum / 2;

    bool ans = solveUsingSO2(nums, target, index);

    if (ans)
    {
        cout << "Equal Subset sum exists" << endl;
    }
    else
    {
        cout << "Equal Subset sum do not exists" << endl;
    }
    return 0;
}