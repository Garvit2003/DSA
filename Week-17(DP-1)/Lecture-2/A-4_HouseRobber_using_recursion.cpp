#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(vector<int> &nums, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    // include
    int include = solveUsingRecursion(nums, n - 2) + nums[n];

    // exclude
    int exclude = solveUsingRecursion(nums, n - 1) + 0;

    return max(include, exclude);
}

int main()
{
    vector<int> nums{1, 2, 3, 1};
    int n = nums.size() - 1;

    int ans = solveUsingRecursion(nums, n);

    cout << "Answer is " << ans << endl;
}