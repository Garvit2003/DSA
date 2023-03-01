#include <iostream>
#include <vector>
using namespace std;

int main(){

    int rows, cols;
    int i,j;

    int arr[i][j];

    // row wise input

    // taking input
    cout<< "Enter the input values in array  "<<endl;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            cin>>arr[i][j];
        }
    }

    // printing array
    cout<<"Printing the values in array" << endl;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
    }
}