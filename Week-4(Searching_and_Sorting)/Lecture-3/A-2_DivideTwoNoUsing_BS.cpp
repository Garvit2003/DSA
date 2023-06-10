#include <iostream>
#include <vector>
using namespace std;

int solve(int &dividend, int &divisor)
{

    int s = 0;
    int e = abs(dividend);
    int mid = s + (e - s) / 2;

    int ans = 0;

    while (s <= e)
    {
        if (abs(mid * divisor) == abs(dividend))
        {
            // perfect solution
            ans = mid;
            break;
        }

        if (abs(mid * divisor) > abs(dividend))
        {
            // left search
            e = mid - 1;
        }
        if (abs(mid * divisor) < dividend)
        {
            // ans store
            ans = mid;
            // right search
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    if ((divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0))
        return ans;
    else
        return -ans;
}

int main()
{

    int dividend = -21;
    int divisor = 7;

    int ans = solve(dividend, divisor);
    cout << "Ans is " << ans << endl;

    return 0;
}