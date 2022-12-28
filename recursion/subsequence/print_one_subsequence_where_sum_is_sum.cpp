#include<bits/stdc++.h>
using namespace std;

bool print_sub(int ind, vector<int> &ds, int sum, vector<int> arr, int n, int s){
    if(ind == n){
        if (sum == s){
            for(auto it : ds){
                cout << it << " ";

            }
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    sum+=arr[ind];
    if(print_sub(ind+1,ds,sum,arr,n,s)) return true;

    ds.pop_back();
    sum-=arr[ind];
    if(print_sub(ind+1,ds,sum,arr,n,s)) return true;

    return false;
}

int main(){

    vector<int> arr = {2,1,2};
    int n = arr.size();
    int s = 2;
    vector<int> ds;

    print_sub(0,ds,0,arr,n,s);
    return 0;
}