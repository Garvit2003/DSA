#include <iostream>
#include <vector>
using namespace std;

int firstOccourence(vector<int> &arr, int target)
{

    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        // ans store and move left
        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }

        else if (arr[mid] > target)
        {
            // move left
            end = mid - 1;
        }

        else if (arr[mid] < target)
        {
            // move right
            start = mid + 1;
        }
        // BUG WAS HERE
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccourence(vector<int> &arr, int target)
{

    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        // ans store and move right
        if (arr[mid] == target)
        {
            ans = mid;
            start = mid + 1;
        }

        else if (arr[mid] > target)
        {
            // move left
            end = mid - 1;
        }

        else if (arr[mid] < target)
        {
            // move right
            start = mid + 1;
        }
        // BUG WAS HERE
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{

    vector<int> arr{1, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 6, 7};
    int target;
    cout << "Enter the Number to find its occourence: " << endl;
    cin >> target;

    int indexOfFirstOccourence = firstOccourence(arr, target);
    int indexOfLastOccourence = lastOccourence(arr, target);
    int totalOccourence = indexOfLastOccourence - indexOfFirstOccourence + 1;

    if (indexOfFirstOccourence == -1 || indexOfLastOccourence == -1)
    {
        cout << "Numbber does not exist in the array" << endl;
    }
    else
    {
        cout << "First Occourence of " << target << " is at index " << indexOfFirstOccourence << endl;
        cout << "Last Occourence of " << target << " is at index " << indexOfLastOccourence << endl;
        cout << "Total Occourence of " << target << " is " << totalOccourence << endl;
    }

    return 0;

    //     cout << "Hello World" << endl;
}