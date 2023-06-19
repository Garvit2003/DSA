#include <iostream>
#include <vector>
using namespace std;

int solveUsingSO(vector<int> weight, vector<int> value, int n, int capacity)
{
    // step1: create dp array
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // base case-only 1 item
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            prev[w] = value[0];

        else
            prev[w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int wt = 0; wt <= capacity; wt++)
        {
            // include
            int include = 0;
            if (weight[index] <= wt)
            {
                include = value[index] + prev[wt - weight[index]];
            }

            // exclude
            int exclude = prev[wt];

            curr[wt] = max(include, exclude);
        }
        // shift:pehle pura curr chal toh jaye tab shift krna hai
        // NOTE: yhaa fasunga
        prev = curr;
    }
    return prev[capacity];
}

int main()
{
    vector<int> weight{4, 5, 1};
    vector<int> value{1, 2, 3};

    // int weight[]={4, 5, 1};
    // int value[]={1, 2, 3};
    int n = 3;
    // int index = n;
    int capacity = 4;

    int ans = solveUsingSO(weight, value, n, capacity);

    cout << "Answer is: " << ans << endl;
}