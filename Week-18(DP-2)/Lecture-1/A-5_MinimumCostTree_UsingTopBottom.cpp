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

    // Step 3: Check if ans already exists
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int ans = INT_MAX;
    for (int i = left; i <= right; i++)
    {
        ans = min(ans, maxi[{left, i}] + maxi[{i + 1, right}] + solveUsingMem(arr, maxi, left, i - 1, dp) + solveUsingMem(arr, maxi, i + 1, right, dp));
    }
    dp[left][right] = ans;
    return dp[left][right];
}

int main()
{
    vector<int> arr{6, 2, 4};
    map<pair<int, int>, int> maxi;

    vector<vector<int>> dp(3, vector<int>(3, -1));

    // pre computation
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
        }
    }

    int n = arr.size();
    int ans = solveUsingMem(arr, maxi, 0, n - 1, dp);
    cout << ans << endl;
    return ans;
}