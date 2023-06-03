#include <iostream>
#include <limits.h>
using namespace std;

void maxElement(int arr[], int n, int i, int &maxi)
{

    // base case
    if (i == n)
    {
        // array agr khatam ho gya, poora traverse hogya toh wapas ajao
        return;
    }

    // ek case solve krdo
    // current element ko check kro for max
    if (arr[i] > maxi)
    {
        maxi = arr[i];
    }

    // baki recursion sambhal lega
    maxElement(arr, n, i + 1, maxi);
}

int main()
{
    int arr[] = {10, 30, 21, 44, 32, 17, 19, 66};
    int n = 8;
    int i = 0;

    int maxi = INT_MIN;

    maxElement(arr, n, i, maxi);

    cout << "Max element is: " << maxi << endl;
}