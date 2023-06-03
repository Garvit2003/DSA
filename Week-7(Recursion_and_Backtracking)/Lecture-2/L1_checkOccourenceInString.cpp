#include <iostream>
using namespace std;

bool checkOccourence(string &str, int i, int &n, char &key)
{

    // base case
    if (i >= n)
    {
        cout << "Base case hit" << endl;
        return false;
    }

    // ek case solve krdo
    cout << "Checking: " << str[i] << endl;
    if (str[i] == key)
    {
        cout << "Found " << str[i] << endl;
        return true;
    }

    //  baki recursion sambhal lega
    return checkOccourence(str, i + 1, n, key);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    int i = 0;

    bool ans = checkOccourence(str, i, n, key);

    cout << "Answer is: " << ans << endl;
    return 0;
}
