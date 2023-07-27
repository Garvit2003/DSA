#include <iostream>
#include <vector>
using namespace std;

int bottomUp(vector<int> &nums, int n)
{
    // step1:create dp array
    vector<int> dp{n + 1, 0};

    // step2:base case
    dp[0] = nums[0];

    // step3:topdown se observe
    for (int i = 0; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
        {
            temp = dp[i - 2];
        }
        int include = temp + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n];
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int n = nums.size() - 1;

    int ans = bottomUp(nums, n);
    cout << "Answer is " << ans << endl;
}