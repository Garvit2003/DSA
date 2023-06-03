#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(string str, string output, int i, vector<string> &arr)
{

    // base case
    if (i >= str.length())
    {
        // cout << output << endl;
        // storing
        arr.push_back(output);
        return;
    }

    // recursive relation
    // exclude
    printSubsequence(str, output, i + 1, arr);

    // include
    output.push_back(str[i]);
    printSubsequence(str, output, i + 1, arr);
}

int main()
{
    string str = "abc";
    string output = "";
    vector<string> arr;
    int i = 0;

    printSubsequence(str, output, i, arr);

    cout << "Printing all subsequences" << endl;
    for (auto val : arr)
    {
        cout << val << " ";
    }

    cout << endl
         << "Size of the array is: " << arr.size() << endl;

    return 0;
}