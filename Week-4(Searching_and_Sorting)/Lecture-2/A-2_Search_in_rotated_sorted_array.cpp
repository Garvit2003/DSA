#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int end)
{

    int mid = (start + end) / 2;

    while (start <= end)
    {

        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        else if (target < element)
        {
            // search in left
            end = mid - 1;
        }
        else
        {
            // search in right
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }

    // element not found
    return -1;
}

int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid - 1 >= 0 && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }

        if (arr[s] >= arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int search(vector<int> arr, int target, int pivotIndex)
{
    if (target >= arr[0] && target <= arr[pivotIndex])
    {
        // search in array A
        int ans = binarySearch(arr, target, 0, pivotIndex);
        return ans;
    }

    if (pivotIndex + 1 < arr.size() && target >= arr[pivotIndex + 1] && target <= arr[arr.size() - 1])
    {
        // search in array B
        int ans = binarySearch(arr, target, pivotIndex + 1, arr.size() - 1);
        return ans;
    }
}

int main()
{

    vector<int> v{4, 5, 6, 7, 0, 1, 2};

    int pivotIndex = findPivot(v);
    cout << "Pivot index is " << pivotIndex << endl;

    int target = 1;

    int finalAns = search(v, target, pivotIndex);
    cout << "The target element is at index " << finalAns << endl;
}