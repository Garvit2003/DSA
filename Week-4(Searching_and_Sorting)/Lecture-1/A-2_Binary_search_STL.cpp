#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// FOR VECTOR
// int main()
// {
//     vector<int> v{1, 2, 3, 4, 5, 6};

//     if (binary_search(v.begin(), v.end(), 2))
//     {
//         cout << "Found" << endl;
//     }

//     else
//     {
//         cout << "Not Found" << endl;
//     }

//     return 0;
// }

// FOR ARRAY
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (binary_search(arr, arr + size, 20))
    {
        cout << "Found" << endl;
    }

    else
    {
        cout << "Not Found" << endl;
    }
}
