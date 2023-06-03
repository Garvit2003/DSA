#include <iostream>
#include <vector>
using namespace std;

void findAllOccourence(string &str, int i, int &n, char &key, int &count)
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
        // cout << "Found at " << i << endl;
        // ans.push_back(i);
        count++;
    }

    //  baki recursion sambhal lega
    return findAllOccourence(str, i + 1, n, key, count);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    // vector<int> ans;

    int count = 0; /* Pass by reference hogi because count ke andar ans ko store krna hai */

    int i = 0;

    findAllOccourence(str, i, n, key, count);

    cout << count << endl;

    // for (auto val : ans)
    // {
    //     cout << val << " ";
    // }

    return 0;
}