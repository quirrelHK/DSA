#include<bits/stdc++.h>
using namespace std;

int count_sub(int ind, vector<int> arr, int n){
    if(ind >= n){
        return 1;
    }

    int l = count_sub(ind+1,arr,n);
    int r = count_sub(ind+1,arr,n);

    return l+r;
}

int main(){

    vector<int> arr = {1,3,2,5};
    int n = arr.size();


    cout << count_sub(0,arr,n);
    return 0;
}