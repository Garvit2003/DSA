#include <iostream>
#include <vector>
using namespace std;

bool solveUsingRecursion(int index, int target, vector<int> &nums)
{

    // Base case
    if (index >= nums.size())
        return 0;

    if (target < 0)
        return 0;

    if (target == 0)
        return 1;

    bool include = solveUsingRecursion(index + 1, target - nums[index], nums);
    bool exclude = solveUsingRecursion(index + 1, target, nums);

    return (include || exclude);
}

int main()
{
    vector<int> nums{1, 5, 11, 6};

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
    bool ans = solveUsingRecursion(index, target, nums);

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