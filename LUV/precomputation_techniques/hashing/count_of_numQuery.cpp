/*
Given array a of N intergers. Given Q queries and in each query
given a number X, print count of that number in array.

Constraints
1 <= Q <= 10^5
1 <= N <= 10^5
1 <= a[i] <= 10^7
*/
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin >> arr[i]; 
    }
    long long hash[N]={0};
    for(int i=0;i<n;++i){
        hash[arr[i]]++;
    }
    int q;
    cin >>q;
    while(q--){
        int x;
        cin >> x;
        cout << hash[x] << endl;
    }
}