#include <iostream>
#include <vector>
using namespace std;

int main(){
    // create vector
    // vector<int>arr();
    vector<int>arr(10);

    int ans=(sizeof(arr)/sizeof(int));
    cout<<ans<<endl;

    arr.push_back(51);
    arr.push_back(52);
    arr.push_back(53);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Size of arr is:"<<arr.size()<<endl;
    cout<<"Capacity of arr is:"<<arr.capacity()<<endl;

    // insert
    arr.push_back(5);
    arr.push_back(6);

    // print
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // remove
    arr.pop_back();

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int n;
    cout<<"Enter the value of n "<<endl;
    cin>>n;

    // vector<int>brr(10);
    // vector<int>brr(10,-1);
    vector<int>brr(n,-1);
    cout<<"Size of b "<<brr.size()<<endl;
    cout<<"capacity of b "<<brr.capacity()<<endl;

    for(int i=0;i<brr.size();i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;
    

    vector<int>crr{10,20,30,50};
    cout<<"Printing crr"<<endl;
    for(int i=0;i<crr.size();i++){
        cout<<crr[i]<<" ";
    }
    cout<<endl;

    cout<<"Vector crr is empty or not: "<<crr.empty()<<endl;

    vector<int>drr;
    cout<<"Vector drr is empty or not: "<<drr.empty()<<endl;

    return 0;
}