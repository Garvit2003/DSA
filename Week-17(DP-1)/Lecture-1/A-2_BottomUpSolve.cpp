#include <iostream>
#include <vector>
using namespace std;

int bottomUpSolve(int n)
{
    // step-1:Create dp array
    vector<int> dp(n + 1, -1);

    // step-2:Observe base case in topBottomSolve and write values
    dp[0] = 0;
    dp[1] = 1;
    if (n == 0)
    {
        return dp[0];
    }
    // step-:observe the behaviour of n in topBottomSolve
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "enter the value of n " << endl;
    cin >> n;

    int fib = bottomUpSolve(n);

    cout << "Value of dp is " << fib << endl;
}