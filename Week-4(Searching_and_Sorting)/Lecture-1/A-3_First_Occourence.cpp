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

int main()
{

    vector<int> arr{1, 3, 4, 4, 4, 4, 6, 7};
    int target = 4;

    int indexOfFirstOccourence = firstOccourence(arr, target);

    cout << "Answer is " << indexOfFirstOccourence << endl;

    return 0;

    //     cout << "Hello World" << endl;
}