#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &arr, int &n, int i)
{

    // base case
    if (i == n - 1)
    {
        cout << "Base case hit" << endl;
        return true;
    }

    // cout << "Element to be checked " << arr[i] << endl;
    // ek case sambhal lo
    if (arr[i + 1] < arr[i])
    {
        return false;
    }

    // baki recursion sambhal lega
    return checkSorted(arr, n, i + 1);
}

int main()
{

    vector<int> arr{10, 20, 30, 90, 50, 60};
    int n = arr.size();
    int i = 0;
    bool isSorted = checkSorted(arr, n, i);

    if (isSorted)
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }

    return 0;
}