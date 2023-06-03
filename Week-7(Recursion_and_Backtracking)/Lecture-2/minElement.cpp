#include <iostream>
#include <limits.h>
using namespace std;

void minElement(int arr[], int n, int i, int &min)
{

    // base case
    if (i == n)
    {
        // array agr khatam ho gya, poora traverse hogya toh wapas ajao
        return;
    }

    // ek case solve krdo
    // current element ko check kro for max
    if (arr[i] < min)
    {
        min = arr[i];
    }

    // baki recursion sambhal lega
    minElement(arr, n, i + 1, min);
}

int main()
{
    int arr[] = {10, 30, 21, 44, 32, 17, 19, 66};
    int n = 8;
    int i = 0;

    int min = INT_MAX;

    minElement(arr, n, i, min);

    cout << "Min element is: " << min << endl;
}