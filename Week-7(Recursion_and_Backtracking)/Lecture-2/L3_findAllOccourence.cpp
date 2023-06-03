#include <iostream>
using namespace std;

void findAllOccourence(string &str, int i, int &n, char &key)
{

    // base case
    if (i >= n)
    {
        // cout << "Base case hit" << endl;
        return;
    }

    // ek case solve krdo
    // cout << "Checking: " << str[i] << endl;
    if (str[i] == key)
    {
        // cout << "Found " << str[i] << endl;
        cout << "Found at " << i << endl;
    }

    //  baki recursion sambhal lega
    return findAllOccourence(str, i + 1, n, key);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    int i = 0;

    findAllOccourence(str, i, n, key);

    return 0;
}