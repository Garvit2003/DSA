#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;

int solveUsingRec(string a, string b, int i, int j)
{
    if (i == a.size())
    {
        return 0;
    }
    if (j == b.size())
    {
        return 0;
    }
    if (a[i] == b[j])
    {
        return 1 + solveUsingRec(a, b, i + 1, j + 1);
    }
    else
    {
        return max(solveUsingRec(a, b, i + 1, j), solveUsingRec(a, b, i, j + 1));
    }
}

int main()
{
    string a = "abc";
    string b = "abcde";

    int i = 0;
    int j = 0;

    int ans = solveUsingRec(a, b, i, j);
    cout << "Answer is: " << ans << endl;
}