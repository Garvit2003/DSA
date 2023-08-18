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
    for (int i = 1; i <= n; i++)
    {

        int include = (i - 2 >= 0 ? dp[i - 2] : 0) + nums[i];
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