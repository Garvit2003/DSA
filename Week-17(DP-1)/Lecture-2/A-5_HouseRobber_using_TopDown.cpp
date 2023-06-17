#include <iostream>
#include <vector>
using namespace std;

int topDown(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // include
    int include = topDown(nums, n - 2, dp) + nums[n];

    // exclude
    int exclude = topDown(nums, n - 1, dp) + 0;

    dp[n] = max(include, exclude);
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int n = nums.size() - 1;

    vector<int> dp(n + 1, -1);

    int ans = topDown(nums, n, dp);

    cout << "Answer is " << ans << endl;
}