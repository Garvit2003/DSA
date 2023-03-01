#include <iostream>
using namespace std;

int main(){
    int arr[9]={1,2,3,4,5,6,7,8,9};
    int size=9;

    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<endl;
    // }

    int start=0;
    int end=size-1;

    while(true){
        if(start>end)
            break;

        if(start==end){
            cout<<arr[start]<<" ";
        }
        else{
            cout<<arr[start]<<" ";
            cout<<arr[end]<<" ";

        }

        start++;
        end--;
    }

    return 0;

}

