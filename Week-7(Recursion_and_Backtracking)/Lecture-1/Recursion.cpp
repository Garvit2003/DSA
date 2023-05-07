#include <iostream>
using namespace std;

int factorial(int n)
{
    cout << "Function is called for n:" << n << endl;

    // base case
    if (n == 1)
        return 1;

    int chotiProblemAns = factorial(n - 1);
    int badiProblemAns = n * chotiProblemAns;

    // int ans = n * factorial(n - 1);
    return badiProblemAns;
}

int main()
{

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int ans = factorial(n);

    cout << "Answer is: " << ans << endl;
}
