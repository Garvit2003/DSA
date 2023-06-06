#include <iostream>
#include <vector>
using namespace std;

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

    vector<int> arr{1, 3, 4, 4, 4, 4, 6, 7};
    int target = 4;

    int indexOFLastOccourence = lastOccourence(arr, target);

    cout << "Answer is " << indexOFLastOccourence << endl;

    return 0;

    //     cout << "Hello World" << endl;
}