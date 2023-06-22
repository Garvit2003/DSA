#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingTab(string a, string b, int i, int j)
{

    vector<int> prev(b.size() + 1, 0);
    vector<int> curr(a.size() + 1, 0);

    for (int i = a.size() - 1; i >= 0; i--)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + prev[j + 1];
            }
            else
            {
                ans = max(prev[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        // next
        prev = curr;
    }

    return curr[0];
}

int main()
{
    string a = "abc";
    string b = "abcde";

    int i = 0;
    int j = 0;

    int ans = solveUsingTab(a, b, i, j);
    cout << "Answer is: " << ans << endl;
}