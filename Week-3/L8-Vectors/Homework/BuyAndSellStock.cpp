#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void maxProfit(int prices[], int n){
    int buy=prices[0];
    int max_profit=0;
    for(int i=0;i<n;i++){
        if(buy>prices[i]){
            buy=prices[i];
        }
        else if(prices[i]-buy>max_profit){
            max_profit=prices[i]-buy;
        }
    }
    cout<<"Maximum Profit is:"<<max_profit<<endl;
}

int main(){
    int prices[]={7,1,5,6,4};
    int n=sizeof(prices)/sizeof(prices[0]);

    maxProfit(prices,n);

    return 0;
}