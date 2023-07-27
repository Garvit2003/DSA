#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int recursiveSolution(vector<int> &house, int n)
{
    // base case
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return house[0];
    }

    // recursive relation
    int exclude = recursiveSolution(house, n - 1);
    int include = recursiveSolution(house, n - 2) + house[n];

    return max(include, exclude);
}

int main()
{
    vector<int> house{1, 2, 3, 1};
    int n = house.size() - 1;

    int ans = recursiveSolution(house, n);
    cout << "The maximum amount of money is: " << ans << endl;
    return 0;
}