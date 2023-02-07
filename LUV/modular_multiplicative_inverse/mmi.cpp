#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int binExp(int a, int b){
    int res=1;
    while (b>0)
    {
        if(b&1){
            res = (res* 1LL * a)%mod;
        }
        a = (a * 1LL * a)%mod;
        b = b>>1;
    }
    return res;
    
}

/*
There are N children and K toffees. K < N, count the number of ways to distribute
toffee among N children such that each child get 1 toffee only --> nCk
N < 10^6
K < N < 10^6
Q < 10^5

n!((n-r)! * r!)
*/

const int N = 1e6+10;
int fact[N]={1};
int main(){

    // cout << (binExp(2,mod-2))%mod << endl;  // MMI of 2

    fact[0]=1;
    for(int i=1;i<=N;++i){
        fact[i] = (i* 1LL *fact[i-1])%mod;
    }
    int q;
    cin >> q;
    while(q--){
        int n,k;
        cin >> n >> k;
        int ans = fact[n];
        int denominator = (fact[n-k]*1LL*fact[k])%mod;
     
        ans = (ans* 1LL *binExp(denominator,mod-2))%mod;
        cout << ans << endl;
    }

}