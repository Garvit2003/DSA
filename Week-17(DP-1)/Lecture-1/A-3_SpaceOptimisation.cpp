#include <iostream>
#include <vector>
using namespace std;

int spaceOptimisation(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    if (n == 0)
        return prev2;

    if (n == 1)
        return prev1;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev1 = curr;
        prev2 = prev1;
    }
    return curr;
}

int main()
{
    int n;
    cout << "enter the value of n " << endl;
    cin >> n;

    int fib = spaceOptimisation(n);

    cout << "Value of dp is " << fib << endl;
}