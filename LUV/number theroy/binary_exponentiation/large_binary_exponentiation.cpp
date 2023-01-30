#include<bits/stdc++.h>
using namespace std;
const long long M = 1e18+7;

/*
    Some assumptions we took: a <= 1e9, b <= 1e9, M <= 1e9 (MAX value of int)
*/

/*
    What if: a or M ~ 1e18
*/

// Not when b <= 10^18
long long binMultiply(long long, long long);
long long binExp(long long a, long long b){
    
    long long res=1;
    while(b>0){
        if(b&1){
            res = binMultiply(res,a);
        }
        a = binMultiply(a,a);
        b = b >> 1;
    }

    return res;
}//O(log^2(b))

long long binMultiply(long long a, long long b){
    // Same as binExp but here instead of doing multiplication we will do addition
    // Basically for a*b we will just add a b number of times
    long long res=0;
    while(b>0){
        if(b&1){
            res = (res +a)%M;
        }
        a = (a+a)%M;
        b = b >> 1;
    }
    // cout << res << endl;
    return res;
}
int main(){

    // cout << binExp(100,13) << endl;
    // cout << setprecision(30) <<  pow(100,13) << endl;
    cout << binMultiply(2,20) << endl;
}