#include <iostream>
#include <vector>
using namespace std;

// first method
int findPeakIndex(vector<int> &arr, int mid, int start, int end)
{

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            // right search
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}

int main()
{
    vector<int> arr{0, 10, 5, 2};
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;

    int peakIndexInMountainArray = findPeakIndex(arr, mid, start, end);
    cout << "Peak Element index is " << peakIndexInMountainArray << endl;
    cout << "Peak Element is " << arr[mid] << endl;
}

// 2nd method

// int findPeakIndex(vector<int> &arr)
// {

//     int start = 0;
//     int end = arr.size() - 1;
//     int mid = start + (end - start) / 2;

//     while (start < end)
//     {
//         if (arr[mid] < arr[mid + 1])
//         {
//             // right search
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return mid;
// }

// int main()
// {
//     vector<int> arr{0, 10, 5, 2};

//     int peakIndexInMountainArray = findPeakIndex(arr);
//     cout << "Peak Element index is " << peakIndexInMountainArray << endl;
//     cout << "Peak Element is " << arr[peakIndexInMountainArray] << endl;
// }