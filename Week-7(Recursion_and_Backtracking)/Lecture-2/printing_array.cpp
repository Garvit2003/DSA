#include <iostream>
#include <unordered_map>
using namespace std;

void print(int arr[], int n, int i)
{
    // base case
    if (i >= n)
    {
        return;
    }
    // ek case solve krdo
    cout << arr[i] << endl;

    // baki recursion sambhal lega
    print(arr, n, i + 1);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int n = 5;

    int i = 0;

    print(arr, n, i);
}