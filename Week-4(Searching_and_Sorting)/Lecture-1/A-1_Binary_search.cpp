#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == target)
        {
            return mid;
        }

        // search left
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }

        // right search
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }

    // element not found
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 16};
    int size = 7;
    int target = 2;

    int IndexOFTarget = binarySearch(arr, size, target);

    if (IndexOFTarget == -1)
    {
        cout << "Target not found" << endl;
    }

    else
    {
        cout << "Target found at " << IndexOFTarget << " index" << endl;
    }

    return 0;
}
