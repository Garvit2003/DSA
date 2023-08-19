#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{

    // step 1: base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // Step 2:recursive relation
    // agr weight kam hoga capacity se tabhi include karenge na
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = solveUsingRecursion(weight, value, index - 1, capacity - weight[index]) + value[index];
    }
    int exclude = solveUsingRecursion(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int solveUsingMemoisation(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{

    // step 1: base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // step 3: check if ans already exists
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    // agr weight kam hoga capacity se tabhi include karenge na
    int include = 0;
    if (weight[index] <= capacity)
    {
        // include = dp[index - 1][capacity - weight[index]] + value[index];
        include = solveUsingMemoisation(weight, value, index - 1, capacity - weight[index], dp) + value[index];
    }
    // int exclude = dp[index - 1][capacity];
    int exclude = solveUsingMemoisation(weight, value, index - 1, capacity, dp);

    // step 2: store ans in dp
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int solveUsingTabulation(int weight[], int value[], int n, int capacity)
{

    // Step 1: Create dp array
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // step 2: base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
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

int solveUsingSO(int weight[], int value[], int n, int capacity)
{

    // Step 1: Create dp array
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // step 2: base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + prev[wt - weight[index]];
            }
            int exclude = prev[wt];
            curr[wt] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}

int solveUsingSO2(int weight[], int value[], int n, int capacity)
{

    // Step 1: Create dp array
    vector<int> curr(capacity + 1, 0);

    // step 2: base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >= 0; wt--)
        {
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + curr[wt - weight[index]];
            }
            int exclude = curr[wt];
            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}

int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};

    int n = 3;
    int capacity = 4;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    int ans = solveUsingMemoisation(weight, value, n, capacity, dp);
    cout << "Answer is: " << ans;

    return 0;
}