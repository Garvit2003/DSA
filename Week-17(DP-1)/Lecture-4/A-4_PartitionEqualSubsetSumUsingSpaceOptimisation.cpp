#include <iostream>
#include <vector>
using namespace std;

bool solveUsingSO(int index, int target, vector<int> &nums)
{

    // Step 1:Create dp array
    // 2d array bcz both index and target are changing
    // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));
    vector<int> next(target + 1, 0);
    vector<int> curr(target + 1, 0);

    // Step 2
    for (int i = 0; i < nums.size(); i++)
    {
        next[0] = 1;
    }

    int n = nums.size();

    // Step 3
    for (int index = n - 1; index >= 0; index--)
    {
        for (int t = 1; t <= target; t++)
        {
            bool include = 0;
            if (t - nums[index] >= 0)
            {
                include = next[t - nums[index]];
            }

            bool exclude = next[t];

            curr[t] = (include || exclude);
        }
        next = curr;
    }
    return curr[target];
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

    bool ans = solveUsingSO(index, target, nums);

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