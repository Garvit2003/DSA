#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k, int target)
{

    // base case
    if (n < 0)
    {
        return 0;
    }

    if (n == 0 && target == 0)
    {
        return 1;
    }

    if (n == 0 && target != 0)
    {
        return 0;
    }

    if (n != 0 && target == 0)
    {
        return 0;
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans += solveUsingRecursion(n - 1, k, target - i);
    }
    return ans;
}

int main()
{
    int n = 2;
    int k = 6;
    int target = 7;

    int ans = solveUsingRecursion(n, k, target);

    cout << "Answer is " << ans << endl;
}