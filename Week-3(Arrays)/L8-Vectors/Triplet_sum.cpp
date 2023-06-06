#include <iostream>
#include <vector>
using namespace std;

int main(){

    int sum=80;

    vector<int>arr{10,20,30,40,50,60};
    
    for(int i=0;i<arr.size();i++){
        int element=arr[i];

        for(int j=i+1;j<arr.size();j++){
            int element2=arr[j];

            for(int k=j+1;k<arr.size();k++){
                if(element+element2+arr[k]==sum){
                    cout<<"Pair found"<<"("<<element<<","<<element2<<","<<arr[k]<<")"<<endl;
                }
            }
        }

    }

    return 0;


}