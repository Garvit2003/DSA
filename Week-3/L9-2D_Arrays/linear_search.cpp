#include <iostream>
#include <vector>
using namespace std;

bool findKey(int arr[][3], int rows, int cols, int key){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j]==key){
                return true;
            }
        }
    }
    return false;
}

int main(){

    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {2,4,8}};

    int key=8;
    cout<<findKey(arr,3,3,key);

    return 0;



}
