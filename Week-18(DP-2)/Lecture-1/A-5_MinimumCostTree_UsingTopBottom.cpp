#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
{
    // Base case
    if (left == right)
    {
        return 0;
    }

    int n = arr.size();

    // Step 3: Check if ans already exists
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int ans = INT_MAX;
    for (int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solveUsingMem(arr, maxi, left, i, dp) + solveUsingMem(arr, maxi, i + 1, right, dp));
    }

    // Step 2: Store ans in dp array
    dp[left][right] = ans;
    return dp[left][right];
}

int main()
{
    vector<int> arr{6, 2, 4};
    map<pair<int, int>, int> maxi;

    int n = arr.size();

    // Step 1: Create dp array
    vector<vector<int>> dp(n, vector<int>(n, -1));

    // pre computation
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
        }
    }

    int ans = solveUsingMem(arr, maxi, 0, n - 1, dp);
    cout << ans << endl;
    return ans;
}