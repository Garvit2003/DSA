#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int majorityElement(int arr[], int N){
    int maxCount=0;

    int index=-1;

    for(int i=0;i<N;i++){
        int count=0;
        for(int j=0;j<N;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>maxCount){
            maxCount=count;
            index=i;
        }
    }

    if(maxCount>N/2){
        cout<<"Majority element is "<<arr[index];

    }
    else{
        cout<<"No Majority element";
    }
}

int main(){

    int arr[]={3,4,3,2,5,4,4,4};
    int N=sizeof(arr)/sizeof(arr[0]);

    // function calling

    majorityElement(arr,N);

    return 0;
}