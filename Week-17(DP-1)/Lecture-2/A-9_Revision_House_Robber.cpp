#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recursiveSolution(vector<int> &house, int n)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return house[0];
    }

    // recursive relation
    int exclude = recursiveSolution(house, n - 1);
    int include = recursiveSolution(house, n - 2) + house[n];

    return max(include, exclude);
}

int topDown(vector<int> &house, int n, vector<int> dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return house[0];
    }
    // step 3: check if ans already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int exclude = topDown(house, n - 1, dp);
    int include = topDown(house, n - 2, dp) + house[n];

    // step 2: store ans in dp
    dp[n] = max(include, exclude);
}
int bottomUp(vector<int> &house, int n)
{

    // step 1: Create dp array
    vector<int> dp(n + 1, 0);

    // Step 2: base case
    if (n == 0)
    {
        return house[0];
    }

    // step 3: see top down approach
    for (int i = 0; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
        {
            temp = dp[i - 2];
        }
        int exclude = dp[i - 1] + 0;
        int include = temp + house[i];

        dp[i] = max(include, exclude);
    }
    return dp[n];
}

int spaceOptimisation(vector<int> house, int n)
{
    int prev2 = 0;
    int prev1 = house[0];

    int curr = 0;

    for (int i = 0; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
        {
            temp = prev2;
        }
        int exclude = prev1 + 0;
        int include = temp + house[i];

        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    vector<int> house{1, 2, 3, 1};
    int n = house.size() - 1;

    // step 1: Create dp array
    // vector<int> dp(n + 1, -1);

    int ans = spaceOptimisation(house, n);
    cout << "The maximum amount of money is: " << ans << endl;
    return 0;
}