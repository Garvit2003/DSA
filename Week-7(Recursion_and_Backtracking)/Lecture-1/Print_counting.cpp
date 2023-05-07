#include <iostream>
using namespace std;

void printCounting(int n)
{
    // base call
    if (n == 0)
        return;

    // recursive call
    printCounting(n - 1);

    // processing
    cout << n << " ";
}

int main()
{
    int n;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    printCounting(n);

    return 0;
}