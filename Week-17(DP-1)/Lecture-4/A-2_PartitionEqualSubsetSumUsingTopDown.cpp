#include <iostream>
#include <vector>
using namespace std;

bool solveUsingMem(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
{

    // Base case
    if (index >= nums.size())
        return 0;

    if (target < 0)
        return 0;

    if (target == 0)
        return 1;

    bool include = dp[index + 1][target - nums[index]];
    bool exclude = dp[index + 1][target];

    dp[index][target] = (include || exclude);
    return dp[index][target];
}

int main()
{
    vector<int> nums{1, 5, 11, 5};

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }

    // yhaa hi glti karunga
    if (sum & 1)
    {
        cout << "Equal Subset sum do not exists" << endl;
        return 0;
    }

    int target = sum / 2;
    int index = 0;

    // Step 1:Create dp array
    // 2d array bcz both index and target are changing
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

    bool ans = solveUsingMem(index, target, nums, dp);

    if (ans)
    {
        cout << "Equal Subset sum exists" << endl;
    }
    else
    {
        cout << "Equal Subset sum do not exists" << endl;
    }
    // cout << "Answer is: " << ans << endl;
}