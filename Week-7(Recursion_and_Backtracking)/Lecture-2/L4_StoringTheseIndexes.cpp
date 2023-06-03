#include <iostream>
#include <vector>
using namespace std;

void findAllOccourence(string &str, int i, int &n, char &key, vector<int> &ans)
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
        ans.push_back(i);
    }

    //  baki recursion sambhal lega
    return findAllOccourence(str, i + 1, n, key, ans);
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    vector<int> ans;

    int i = 0;

    findAllOccourence(str, i, n, key, ans);

    for (auto val : ans)
    {
        cout << val << " ";
    }

    return 0;
}