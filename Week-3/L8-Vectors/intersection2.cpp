#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of arr:";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    int m;
    cout<<"Enter the size of brr:"<<endl;
    cin>>m;

    vector<int>brr(m);
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<brr.size();i++){
        cin>>brr[i];
    } 

    // vector<int>arr{1,2,3,4,5,6,7};
    // vector<int>brr{1,5,8};

    vector<int>ans;

    for(int i=0;i<arr.size();i++){
        int element=arr[i];
        for(int j=0;j<brr.size();j++){
            if(element==brr[j]){
                ans.push_back(element);
            }
        }
    }

    for(int k=0;k<ans.size();k++){
        cout<<ans[k]<<" ";
    }

    return 0;



}
 