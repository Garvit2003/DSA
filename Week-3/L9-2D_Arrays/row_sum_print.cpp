#include <iostream>
#include <vector>
using namespace std;

int printSumRowWise(int arr[][3], int rows, int cols){

    for(int i=0;i<rows;i++){
        int sum=0;
        for(int j=0;j<cols;j++){
            sum=sum+arr[i][j];
        }
        cout<<sum<<endl;
    }
    return 0;

}

int main(){

    int rows,cols;
    int arr[4][3]={{1,2,3},{2,3,4},{5,6,1},{2,4,6}};

    printSumRowWise(arr,4,3);

    return 0;
}
