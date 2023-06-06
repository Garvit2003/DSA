#include <iostream>
#include <limits.h>
using namespace std;

 int main(){

    int arr[]={1,54,64,3,6,3,64,03,4,96,6};
    int size=11;

    int maxNum= INT_MIN;
    int minNum= INT_MAX;

    for(int i=0;i<size;i++){
         if(arr[i]>maxNum){
            maxNum=arr[i];
         }
    }

    cout<< "Maximum Number is "<<maxNum<<endl;

    return 0;
 }