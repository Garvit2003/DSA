#include <iostream>
#include <vector>
using namespace std;

int firstOccourence(vector<int> arr, int target)
{

    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            // ans store and then move left
            int ans = mid;
            end = mid - 1;
        }

        else if (target < arr[mid])
        {
            // move left
            end = mid - 1;
        }

        else if (target > arr[mid])
        {
            // move right
            start = mid + 1;
        }

        mid = (start + end) / 2;
    }
}

int main()
{

    vector<int> v{1, 3, 4, 4, 4, 4, 4, 6, 7};
    int target = 6;
    int indexOffirstOccourence = firstOccourence(v, target);

    cout << "Answer is " << indexOffirstOccourence << endl;

    return 0;
}