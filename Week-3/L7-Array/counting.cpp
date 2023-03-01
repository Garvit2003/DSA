#include <iostream>
using namespace std;

int main(){

    int arr[]={0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,1,0};
    int size=17;


    int numone=0;
    int numzero=0;

    for(int i=0;i<size;i++){
        if(arr[i]==0){
            numzero++;
        }
        if(arr[i]==1){
            numone++;
        }
    }

    cout<<"Number of zeroes "<<numzero<<endl;
    cout<<"Number of ones "<<numone<<endl;
}