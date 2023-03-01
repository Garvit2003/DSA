#include <iostream>
using namespace std;

int main(){

    int i,j,m,n;
    cin>>n;

    for(i=0;i<n;i++){

        for(j=0;j<i;j++){
            cout<<" ";
        }

        // for(j=0;j<n-i;j++){
        // for(j=0;j<n-i+1;j++){
        for(j=0;j<n-i-1;j++){
            cout<<"*";
        }

        for(j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}