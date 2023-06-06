#include <iostream>
using namespace std;

int main(){
    int arr[10];

// taking input
    cout<< "Enter the input values in array  "<<endl;
    for(int i=0; i<10; i++){
        cin>> arr[i];

    }
// printing1 
    cout<<"Printing the values in array" << endl;
    for(int i=0; i<10;i++){
        cout<< arr[i]<<" ";
    }
}