#include <iostream>
using namespace std;
#include <vector>

int firstOccurence(vector<int> arr,int target){

    int start=0;
    int end=arr.size()-1;
    int mid=(start+end)/2;
    int ans=-1;

    while(start<=end){
        if(arr[mid]==target){
            // ans store and then move left
            int ans=mid;
            end=mid-1;
        }

        else if(target<arr[mid]){
            // move left
            end=mid-1;
        }

        else if(target>arr[mid]){
            // move right
            start=mid+1;
        }

        mid=(start+end)/2;
    }
    
}

int LastOccurence(vector<int> arr,int target){

    int start=0;
    int end=arr.size()-1;
    int mid=start+(end-start)/2;
    int ans=-1;

    while(start<=end){
        if(arr[mid]==target){
            // store ans and move right
            int ans=mid;
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

    vector<int> v{1,5,6,7,7,7,7,7,7,7,7,9};
    int target=7;

    int indexOfFirstOccourence= firstOccurence(v,target);
    cout<<"Answer is "<<indexOfFirstOccourence<<endl;


    int indexOfLastOccourence=LastOccurence(v,target);
    cout<<"Answer is "<<indexOfLastOccourence<<endl;

    int a=indexOfFirstOccourence;
    int b=indexOfLastOccourence;

    int ans=b-a+1;

    int totalOccourence=ans;

    cout<<"Ans is "<<totalOccourence<<endl;

    return 0;

}