#include <iostream>
using namespace std;

int main(){

    int i,j,n,m;
    cin>>n;
    cin>>m;
    

    for(i=0;i<n;i++){

        if(i==0||i==n-1){
            for(j=0;j<m;j++){
                cout<<"*";
            }
        }
        else{
            cout<<"*";
            for(j=0;j<m-2;j++){
                cout<<" ";
            }
            cout<<"*";
        }
        cout<<endl;
    }
}