// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

/*
We have K symbols in the alphabet; size of the password in N; N < K
Choosing N symbols from K symbols: KCN = (K!)/(N!*(K-N)!)
No. of ways we can make a password from N symbols: N!

ans = N! * KCN
*/


#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e5+10;
int fact[N];


int binExp(int a, int b, int mod){
    int res=1;
    while(b > 0){
        if(b&1){
            res = (res * 1LL * a)%mod;
        }
        a = (a * 1LL * a)%mod;
        b = b >> 1;
    }
    return res;
}
int main(){
    fact[0] = 1;
    for(int i=1;i<N;++i){
        fact[i] = (fact[i-1]* 1LL *i)%MOD;
    }
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int ans = fact[n];
        ans = (ans * 1LL * fact[k])%MOD;
        int denominator = (fact[n]*1LL*fact[k-n])%MOD;
        ans = (ans * 1LL * binExp(denominator, MOD-2,MOD))%MOD;
        cout << ans << endl;
    }

}