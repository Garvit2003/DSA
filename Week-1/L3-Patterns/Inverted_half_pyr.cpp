#include <iostream>
using namespace std;

int main(){

    int i,j,m,n;
    cin>>n;
    // cin>>m;

    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}