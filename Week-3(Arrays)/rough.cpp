#include <iostream>
using namespace std;

// int solution(int a, int b){

//     int sum=a +b;

//     return sum;
        
//     }

// int main(){

//     int param1=1;
//     int param2=2;

//     cout<<solution(param1,param2)<<endl;

    
// }


const int N=1e5;
int composites[N];
set<int>primes;
void sieve(){
    primes.insert(1);
    for(int i=2;i<=N;i++){
        if(composites[i]==0){
            composites[i]=i;
            primes.insert(i);
            for(long long int j=i*1;j<N && j>0;j+=1){
                if(composites[j]==0){
                    composites[j]=i;
                }
            }
        }
    }
}

string solution(int n, vector<int>arr){
    sieve();
    int lim=0;
    for(int i=0;i<n;i++){
        int f=arr[i]-lim;
        auto it=primes.upper_bound(f);
        it--;
        int val=arr[i]-(*it);
        if(val<lim){
            return"NO";
        }
        else{
            lim=val+1;
        }
    }
    return "YES";
}