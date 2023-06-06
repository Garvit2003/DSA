#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int &key, int &n)
{

    // Base case
    if (start >= end)
    {
        cout << "Base case hit" << endl;
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        cout << "mid found" << endl;
        return mid;
    }

    // ek case solve krdo
    if (arr[mid] > key)
    {
        end = mid - 1;
    }
    else
    {
        start = mid + 1;
    }

    // baki recursion sambhal lega
    //   cout << "start: " << start << " end: " << end << " mid: " << mid << endl;
    return binarySearch(arr, start, end, key, n);
}

int main()
{
    vector<int> arr{10, 20, 44, 60, 70, 90, 99};

    int n = arr.size();

    int start = 0;
    int end = n - 1;
    // int mid = start + (end - start) / 2;
    int key = 20;

    int ans = binarySearch(arr, start, end, key, n);

    cout << "Answer is: " << ans << endl;
}