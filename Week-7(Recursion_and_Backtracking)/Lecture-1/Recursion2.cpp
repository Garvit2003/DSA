#include <iostream>
using namespace std;

int factorial(int n)
{
    cout << "Function is called for n: " << n << endl;

    if (n == 1)
        return 1;

    int ans = n * factorial(n - 1);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    int ans = factorial(n);
    cout << "Answer is:" << ans << endl;
    return 0;
}
