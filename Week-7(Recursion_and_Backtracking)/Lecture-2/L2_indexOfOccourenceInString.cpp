#include <iostream>
using namespace std;

int indexOfOccourence(string &str, int i, int &n, char &key)
{

    // base case
    if (i >= n)
    {
        // cout << "Base case hit" << endl;
        return -1;
    }

    // ek case solve krdo
    // cout << "Checking: " << str[i] << endl;
    if (str[i] == key)
    {
        // cout << "Found " << str[i] << endl;
        return i;
    }

    //  baki recursion sambhal lega
    return indexOfOccourence(str, i + 1, n, key);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'g';

    int i = 0;

    int ans = indexOfOccourence(str, i, n, key);

    cout << "Answer is: " << ans << endl;
    return 0;
}