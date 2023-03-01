#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    
    vector<int>arr{1,2,3,4,5,5,6,7};
    vector<int>brr{1,5,5,8};

    vector<int>ans;

    for(int i=0;i<arr.size();i++){
        int element=arr[i];
        for(int j=0;j<brr.size();j++){
            if(element==brr[j]){
                brr[j]=INT_MIN;

                ans.push_back(element);
            }
        }
    }

    for(auto value:ans){
        cout<<value<<" ";
    }
    cout<<endl;

    return 0;

}