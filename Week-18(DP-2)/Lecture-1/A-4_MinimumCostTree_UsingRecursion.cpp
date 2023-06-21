#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingRec(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // Base case
    if (left == right)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = left; i <= right; i++)
    {
        ans = min(ans, maxi[{left, i}] + maxi[{i + 1, right}] + solveUsingRec(arr, maxi, left, i - 1) + solveUsingRec(arr, maxi, i + 1, right));
    }
    return ans;
}

int main()
{
    vector<int> arr{6, 2, 4};
    map<pair<int, int>, int> maxi;

    // pre computation
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
        }
    }

    int n = arr.size();
    int ans = solveUsingRec(arr, maxi, 0, n - 1);
    cout << ans << endl;
    return ans;
}