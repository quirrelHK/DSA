/*
    30 = 2*3*5
    lowest prime->2
    highest prime->5
*/
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
vector<int> isPrime(N,1);
vector<int> lp(N,0), hp(N,0);

int main(){
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<=N;++i){
    
        if(isPrime[i]){
            lp[i] = hp[i] = i;   // The highest and lowest primes of a prime number will be the number itself; since j=2*i we are taking care of it here
            for(int j=2*i;j<=N;j+=i){
                isPrime[j]=false;
                hp[j]=i;            // The last prime that divides the number will be stored
                if(lp[j]==0){       // The first prime that divides the number will be stored
                    lp[j]=i;
                }
            }
        }
    }//N * log(log(N))

    for(int i=2;i<=100;++i){
        cout << lp[i] << " " << hp[i] << endl;
    }
    getchar();

}