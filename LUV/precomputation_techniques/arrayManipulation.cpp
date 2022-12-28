/*
Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element
between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.
(hackerRank)*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;

long long int arr[N];
int main(){
    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b,d;
        cin >> a >> b >> d;
        arr[a]+=d;
        arr[b+1]-=d;
    }
    for(int i=1;i<=n;++i){
        arr[i]+=arr[i-1];
    }
    long long mx = -1;
    for(int i=1;i<=n;++i){
        if(mx<arr[i])
            mx=arr[i];
    }
    cout << mx << endl;
} 
// BruteForce O(m * n + n) = 2*10^5 * 10^7

// PrefixSum O(m + n + n) = 2*10^5 + 10^7 + 10^7 ~ 10^7