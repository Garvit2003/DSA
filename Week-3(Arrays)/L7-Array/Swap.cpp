#include <iostream>
using namespace std;

int main(){

    int arr[7]={10,20,30,40,50,60,70};
    int size=7;

    int start=0;
    int end=size-1;

    while(true){

        if(start>end)
        break;

        if(start==end){
            swap(arr[start],arr[end]);
        }

        else{
            swap(arr[start],arr[end]);
        }

        start++;
        end--;

    }

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}