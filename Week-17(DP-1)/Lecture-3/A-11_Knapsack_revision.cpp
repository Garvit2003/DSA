#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);
    }

    int exclude = solveUsingRecursion(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}
int solveUsingTopDown(int weight[], int value[], int index, int capacity, vector<vector<int>> dp)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
            return 0;
    }

    // step 3: Check if ans already exists

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingTopDown(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = solveUsingTopDown(weight, value, index - 1, capacity, dp);

    // step 2: ans ko dp mein store kro
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int solveUsingTabulation(int weight[], int value[], int n, int capacity)
{
    // Step 1: Create dp array
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // step 2: Base case
    for (int wt = weight[0]; wt <= capacity; wt++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][wt] = value[0];
        }
        else
            dp[0][wt] = 0;
    }

    // step 3: see topDown Approach
    for (int index = 0; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + dp[index - 1][wt - weight[index]];
            }
            int exclude = dp[index - 1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};

    int index = 3;
    int capacity = 4;

    // Step 1: Create dp Array
    vector<vector<int>> dp(index + 1, vector<int>(capacity + 1, -1));

    int ans = solveUsingTopDown(weight, value, index, capacity, dp);
    cout << "Maximum Capacity is: " << ans << endl;

    return 0;
}