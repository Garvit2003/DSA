#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingTab(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    int n = arr.size();

    // Step 1: Create dp array
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int left = n - 1; left >= 0; left--)
    {
        for (int right = 0; right <= n - 1; right++)
        {
            if (left >= right)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                for (int i = left; i < right; i++)
                {
                    ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }
    return dp[0][n - 1];
}
int main()

{
    vector<int> arr{6, 2, 4};
    map<pair<int, int>, int> maxi;

    int n = arr.size();

    // pre computation
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
        }
    }

    int ans = solveUsingTab(arr, maxi, 0, n - 1);
    cout << ans << endl;
}