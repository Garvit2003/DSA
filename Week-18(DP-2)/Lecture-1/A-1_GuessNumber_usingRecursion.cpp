#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solveUsingRec(int start, int end)
{
    // Base case
    if (start >= end)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveUsingRec(start, i - 1), solveUsingRec(i + 1, end)));
    }
    return ans;
}

int main()
{
    int start = 1;
    int end = 10;

    int ans = solveUsingRec(start, end);
    cout << ans << endl;
}