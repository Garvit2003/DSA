#include <iostream>
#include <vector>
using namespace std;

int spaceOptimisation(vector<int> &nums, int n)
{
    int prev2 = 0;
    int prev1 = nums[0];

    int curr = 0;

    for (int i = 0; i <= n; i++)
    {
        int temp = 0;
        if (i - 2 >= 0)
        {
            temp = prev2;
        }
        int include = temp + nums[i];
        int exclude = prev1 + 0;

        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int n = nums.size() - 1;

    int ans = spaceOptimisation(nums, n);
    cout << "Answer is " << ans << endl;
}