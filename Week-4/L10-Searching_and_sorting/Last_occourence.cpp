#include <iostream>
#include <vector>
using namespace std;

int LastOccourence(vector<int> arr,int target){

    int start=0;
    int end=arr.size()-1;
    int mid=start+(end-start)/2;
    int ans=-1;

    while(start<=end){
        if(arr[mid]==target){
            // store ans and move right
            ans=mid;
            start=mid+1;
        }

        else if(target<arr[mid]){
            // move left
            end=mid-1;
        }

        else if(target>arr[mid]){
            // move right
            start=mid+1;
        }

        mid=start+(end-start)/2;  
        }
}

int main(){

    vector<int> v{2,5,6,7,7,7,7,7,9};
    int target=7;

    int indexOfLastOccourence=LastOccourence(v,target);

    cout<<"Answer is "<<indexOfLastOccourence<<endl;

    return 0;
}