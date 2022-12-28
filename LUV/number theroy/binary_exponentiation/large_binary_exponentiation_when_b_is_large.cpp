#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;

// When b <= 10^18

/*
Here M is prime so we can just use:
(a^b)%M = ( a^(b%(M-1)))%M
*/
int binExp(int a, long long b, int m){
    int res=1;
    while(b>0){
        if(b&1){
            res = (res*1LL*a)%M;
        }
        a = (a*1LL*a)%M;
        b = b >> 1;
    }

    return res;
}
int main(){
    // (50 ^ 64 ^ 32) % M
    cout << binExp(50,binExp(64,32,M-1),M) << endl;
}