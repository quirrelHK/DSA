/*
Given array a of N intergers. Given Q queries and in each query
given L and R print sum of array elements from index L and R(both included).

Constraints
1 <= Q <= 10^5
1 <= N <= 10^5
1 <= a[i] <= 10^9
1 <= L,R <=N
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i=1;i<=n;++i){
        cin >> arr[i];
    }
    int pf_sum[n+1]={0};
    for(int i=1;i<=n;++i){
        pf_sum[i] = pf_sum[i-1]+arr[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        cout << pf_sum[r] - pf_sum[l-1] << endl;
    }
}