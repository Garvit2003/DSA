#include <iostream>
#include <vector>
using namespace std;

int solveUsingSpaceOptimisation(int n, int k)
{

    int prev2 = k;
    int prev1 = k + k * (k - 1);

    // Step 3
    for (int i = 3; i <= n; i++)
    {
        int curr = (prev1 + prev2) * (k - 1);
        // shift -- yhii pr glti karunga~
        prev2 = prev1;
        prev1 = curr;
        ;
    }
    return prev1;
}

int main()
{
    int n = 4;
    int k = 3;

    int ans = solveUsingSpaceOptimisation(n, k);
    cout << "Answer is: " << ans << endl;
}