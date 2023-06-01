#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    n--;

    if (n < 0)
    {
        return -1;
    }
    else if (arr[n] == key)
    {
        return n;
    }
    return linearSearch(arr, n, key);
}

int main()
{
    int arr[] = {1, 3, 5, 6, 2, 9};
    int n = 6;
    cout << "the size of the array is " << n << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " << endl;
    }

    int key;
    cout << "Which number u want to search:" << endl;
    cin >> key;

    int ans = linearSearch(arr, n, key);
    if (ans != -1)
    {
        cout << "The key is present at index:" << ans << endl;
    }
    else
    {
        cout << "The key is not present " << endl;
    }
    return 0;
}