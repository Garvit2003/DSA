#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(string str, string output, int i)
{

    // base case
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // recursive rel587\    `QWE457312  `1B Vation

    // exclude
    printSubsequence(str, output, i + 1);

    // include
    output.push_back(str[i]);
    printSubsequence(str, output, i + 1);
}

int main()
{
    string str = "abc";
    string output = "";

    int i = 0;

    printSubsequence(str, output, i);
    return 0;
}