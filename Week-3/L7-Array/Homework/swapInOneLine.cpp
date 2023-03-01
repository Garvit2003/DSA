// C++ program to swap two numbers using arithmetic operators.
#include<bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
int a = 5, b = 8;

cout << "Values before swapping a = " <<
a << " , b = " << b << endl;

b = a - b + (a = b);

cout << "Values after swapping a = " << a <<
" , b = " << b << endl;
return 0;
}
