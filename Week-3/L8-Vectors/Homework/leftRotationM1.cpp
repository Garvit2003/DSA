#include <iostream>
#include <vector>
using namespace std;

void rotate(int arr[],int d,int n){
    int temp[n];

    int k=0;

    for(int i=d;i<n;i++){
        temp[k]=arr[i];
        k++;
    }

    for(int i=0;i<d;i++){
        temp[k]=arr[i];
        k++;
    }

    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }

}

void printArray(int arr[], int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
}

int main(){

    // vector<int>arr{1,2,3,4,5,6};
    int arr[]={1,2,3,4,5,6};
    // int N=sizeof(arr)/sizeof(arr[0]);
    int n=6;

    int d;
    cout<<"The value of d is"<<endl;
    cin>>d;

    // function calling
    rotate(arr,d,n);
    printArray(arr,n);

    return 0;

}