#include <iostream>
#include <vector>
using namespace std;

int main(){

    int sum=60;

    vector<int>arr{10,20,30,40,50};

    for(int i=0;i<arr.size();i++){
        int element=arr[i];

        for(int j=i+1;j<arr.size();j++){
            // to print all pairs
            cout<<"("<<element<<","<<arr[j]<<")"<<endl; 
            // to find sum
            if(element+arr[j]==sum){
                cout<<"Pair found ("<<element<<","<<arr[j]<<")"<<endl;
            }
        }
    }
     
}