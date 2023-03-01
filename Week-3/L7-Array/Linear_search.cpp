#include <iostream>
using namespace std;

bool find(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key)
        return true;

    }
    return false;
}

int main(){
    int arr[]={1,9,88,66,45};
    int size=5;

    cout<<"Enter the key to find "<<endl;
    int key;
    cin>>key;

    if(find(arr,size,key)){
        cout<<"Found"<< endl;
    }

    else{
        cout<< "not found"<< endl;
    }

}