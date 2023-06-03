#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int &key)
{

    // Base case
    // case 2 -key not found
    // s>e invalid array
    if (start >= end)
    {
        cout << "Base case hit" << endl;
        return -1;
    }

    // case 2 - key found
    // ek case solve krdo
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        cout << "mid found" << endl;
        return mid;
    }

    // baki recursion sambhal lega
    // left search
    if (arr[mid] > key)
    {
        return binarySearch(arr, start, mid - 1, key);
    }

    // right search
    else
    {
        return binarySearch(arr, mid + 1, end, key);
    }
}

int main()
{
    vector<int> arr{10, 20, 44, 60, 70, 90, 99};

    int n = arr.size();

    int start = 0;
    int end = n - 1;
    // int mid = start + (end - start) / 2;
    int key = 90;

    int ans = binarySearch(arr, start, end, key);

    cout << "Answer is: " << ans << endl;

    return 0;
}