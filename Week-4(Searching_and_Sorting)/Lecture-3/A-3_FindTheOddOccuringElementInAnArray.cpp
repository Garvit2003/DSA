#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &arr)
{

    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            return s;
        }

        if (mid % 2 == 0)
        {
            // mid is even
            if (arr[mid] == arr[mid + 1])
            {
                // right search
                s = mid + 2;
            }
            else
                // (arr[mid] != arr[mid + 1])

                // left search
                e = mid;
        }

        else
        // (mid % 2 != 0)
        {
            // mid is odd
            if (arr[mid] == arr[mid - 1])
            {
                // right search
                s = mid + 1;
            }
            else
                // (arr[mid] != arr[mid - 1])

                // left search
                e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};
    int ans = solve(arr);

    cout << "Odd occuring element  index is " << ans << endl;
    cout << "Odd occuring element is " << arr[ans] << endl;
    return 0;
}