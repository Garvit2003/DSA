#include <iostream>
using namespace std;

int climbstairs(int n)
{
    if (n == 0 || n == 1)
        return 1;

    int ans = climbstairs(n - 1) + climbstairs(n - 2);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;

    int ans = climbstairs(n);
    cout << "Answer is:" << ans << endl;
}