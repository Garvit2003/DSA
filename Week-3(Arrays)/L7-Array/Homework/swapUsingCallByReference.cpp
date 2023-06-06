// C++ program to swap two
// numbers using call by
// reference
#include<bits/stdc++.h>
using namespace std;

// Function which will swap
// two numbers using call by Reference
void Swap_two_numbers(int *x,
					int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// Driver code
int main()
{
	int a = 2, b = 3;

	cout << "Before swapping a = " <<
			a << " , b = " << b << endl;
	
	// Function call to swap
	Swap_two_numbers(&a, &b);

	cout << "After swapping a = " <<
			a << " , b = " << b << endl;
	return 0;
}
