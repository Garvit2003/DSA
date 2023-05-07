#include <iostream>
#include <vector>
using namespace std;

int findPeakIndex(vector<int>arr){
    int start=0;
    int end=arr.size-1;
    int mid=start+(end-start)/2;

    while(start<end){
        if(arr[mid]<arr[mid+1]){
            // search in right
            start=mid+1;
        }
        else if(arr[mid]>arr[mid+1]){
            end=mid;
        }
        mid=start+(end-start)/2;
    }

    return start;
}

int main(){
    vector<int> v{0,10,5,2};
    int peakIndexInMountainArray=findPeakIndex(v);
    cout<<"Peak Element is "<<peakIndexInMountainArray<<endl;
}