#include <iostream>
using namespace std;

int factorial(int n)
{
    // base case
    if (n == 1)
        return 1;

    // recursive call
    int ans = n * factorial(n - 1);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    factorial(n);

    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    cout << return 0;
}