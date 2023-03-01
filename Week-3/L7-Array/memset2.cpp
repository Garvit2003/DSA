#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    
	int a[5];

	// all elements of A are zero
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;

	// all elements of A are -1
	memset(a, -1, sizeof(a));
	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
	cout << endl;

	// Would not work
	memset(a, 5, sizeof(a)); // WRONG
	for (int i = 0; i < 4; i++)
		cout << a[i] << " ";

    cout<<endl;

    // For Boolean
    bool prime[5];
    memset(prime, true, sizeof(prime));
    // If you print without using boolalpha it will print
    // like this
    for (int i = 0; i < 5; i++)
        cout << prime[i] << " ";
    cout << "\n";
    // If you use boolalpha it will print like this
    for (int i = 0; i < 5; i++)
        cout << boolalpha << prime[i] << " ";
 
    return 0;
}

