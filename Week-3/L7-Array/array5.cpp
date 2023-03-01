#include <iostream>
using namespace std;

int main(){
    int n;
    int arr[]={1,3,5,7,9};

    // arr[1]=1;
    // arr[2]=1;

    for(int i=0;i<5;i++){
        arr[i]=1;
    }
 
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}