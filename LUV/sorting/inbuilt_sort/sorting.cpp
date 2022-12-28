/*
Intro sort(one of the best algos: nlogn )- combination of three algorithms(heap,quick and insertion sort)
1st param- address of location to start sorting
2nd param- address of location just after the last element
3rd param- comparator(key)
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    // int a[n];
    for(int i=0;i<n;++i){
        // cin >> a[i];
        cin >> v[i];

    }
    // sort(a+2,a+n);
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        // cout <<  a[i] <<" ";
        cout <<  v[i] <<" ";
    }
}
