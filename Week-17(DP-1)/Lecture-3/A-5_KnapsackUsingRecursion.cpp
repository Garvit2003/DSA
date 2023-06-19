#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int weight[], int value[], int index, int capacity)
{
    // base case
    // if (index == 0 || capacity == 0)
    // {
    //     return 0;
    // }
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    // recursive case
    // include
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] /*NOTE: yhaa fasunga */ + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);
    }

    // exclude
    int exclude = solveUsingRecursion(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int main()
{
    // vector<int> weight{4, 5, 1};
    // vector<int> value{1, 2, 3};

    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};

    int index = 3;
    int capacity = 4;

    int ans = solveUsingRecursion(weight, value, index, capacity);

    cout << "Answer is: " << ans << endl;
}