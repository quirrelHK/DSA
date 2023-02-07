// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/

/*
    divisors of a-> x
    divisors of b-> y
    divisors of ab-> z

    then x+y will have one extra z. So, ans = x+y-z   (z->lcm(a,b))
*/


#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int multiple_cnt[N]={0};   // Store the count of multiples of ith index

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> hsh;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        hsh[x]++;     // We will only store the count of a number in the array
    }
    for(int i=1;i<N;++i){
        for(int j=i;j<N;j+=i){              // For each multiple of i, we will add its count in the multiple_cnt array
            multiple_cnt[i] += hsh[j];      
        }
    }
    // for(int i=1;i<=10;++i){
    //     cout << i << " " << multiple_cnt[i] << endl;
    // }
    int t;
    cin >> t;
    while(t--){
        int p,q;
        cin >> p >> q;
        long long lcm = (p*1LL*q)/__gcd(p,q);
        long res = multiple_cnt[p]+multiple_cnt[q];
        if(lcm < N){           // 
            res -= multiple_cnt[lcm];
        }
        cout << res << endl;

    }

}