#include <iostream>
#include <vector>
using namespace std;

int solveUsingMem(int weight[], int value[], int index, int capacity, vector<vector<int>> dp)
{
    // base case-only 1 item
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

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // recursive case
    // include
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingMem(weight, value, index - 1, capacity - weight[index], dp);
    }

    // exclude
    int exclude = solveUsingMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int main()
{
    // vector<int> weight{4, 5, 1};
    // vector<int> value{1, 2, 3};

    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    // int index = n;
    int capacity = 4;

    // NOTE:size of array and initialize krne mein fasunga
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    int ans = solveUsingMem(weight, value, n, capacity, dp);

    cout << "Answer is: " << ans << endl;
}