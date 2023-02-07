/*
  Given Q queries, find if number is prime or not for each query.
  1 <= Q <= 10^7, 1 <= N <= 10^7 
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<bool> isPrime(N,1); // Initially all are prime


int main(){
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<=N;++i){
        if(isPrime[i]){
            for(int j = 2*i; j<=N; j+=i){
                isPrime[j]=0;
            }
        }
    } // N * log(log(N))

    // for(int i=1;i<=100;++i){
    //     cout << isPrime[i] << " " <<  i << endl;
    // }

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(isPrime[n]){
            cout << "Prime" << endl;
        }
        else{
            cout << "Not Prime" << endl;
        }
    }
    return 0;
}