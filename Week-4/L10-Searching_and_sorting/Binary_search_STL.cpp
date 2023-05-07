#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int main(){
    vector<int>v{1,2,3,4,5,6};

    if(binary_search(v.begin(),v.end(),2)){
        cout<<"Found"<<endl;
    }

    else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}
