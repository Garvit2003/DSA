#include <iostream>
#include <vector>
using namespace std;

int topDownSolve(int n, vector<int> &dp)
{

    // base case
    if (n == 0 || n == 1)
    {
        return n;
    }

    // step-3:Check if ans already exists
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // step-2:replace ans with dp[n]
    dp[n] = topDownSolve(n - 1, dp) + topDownSolve(n - 2, dp);
    return dp[n];
}

int fib(int n)
{
    // step-1:Create dp array
    vector<int> dp(n + 1, -1);

    int ans = topDownSolve(n, dp);
    return ans;
}

int main()
{
    int n;
    cout << "enter the value of n " << endl;
    cin >> n;

    int finalAnswer = fib(n);

    cout << "Value of dp is " << fib(n) << endl;
}