#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>arr){
    int ans=0;
    for(int j=0;j<arr.size();j++){
        ans=ans^arr[j];
    }
    return ans; 
}

int main(){

    // vector<int>arr(10,-1);

    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i]<<" ";
    // }
    // return 0;

    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;

    vector<int>arr(n);

    cout<<"Enter the elements"<<endl;
     for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    int uniqueElement=find(arr);
    cout<<uniqueElement<<endl;
}
