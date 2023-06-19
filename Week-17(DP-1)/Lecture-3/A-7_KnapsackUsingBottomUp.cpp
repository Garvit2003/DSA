#include <iostream>
#include <vector>
using namespace std;

int solveUsingTab(vector<int> weight, vector<int> value, int n, int capacity)
{
    // step1: create dp array
    // NOTE:size of array and initialize krne mein fasunga

    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // base case-only 1 item
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];

        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // include
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + dp[index - 1][wt - weight[index]];
            }

            // exclude
            int exclude = dp[index - 1][wt];

            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int main()
{
    vector<int> weight{4, 5, 1};
    vector<int> value{1, 2, 3};

    // int weight[]={4, 5, 1};
    // int value[]={1, 2, 3};
    int n = 3;
    // int index = n;
    int capacity = 4;

    int ans = solveUsingTab(weight, value, n, capacity);

    cout << "Answer is: " << ans << endl;
}