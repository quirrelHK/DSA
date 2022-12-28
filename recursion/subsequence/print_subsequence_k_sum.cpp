#include<bits/stdc++.h>
using namespace std;

void print_sub(int ind, vector<int> &ds, int s, vector<int> arr, int sum, int n){
    if(ind==n){
        if (sum == s){
            for(auto it: ds){
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }


    ds.push_back(arr[ind]);
    s+=arr[ind];
    print_sub(ind+1,ds,s,arr,sum,n);

    
    ds.pop_back();
    s-=arr[ind];
    print_sub(ind+1,ds,s,arr,sum,n);
}

int main(){
    vector<int> arr = {1,2,1,5,2,-3,1};
    int n = arr.size();

    vector<int> ds;
    int sum=2;

    print_sub(0,ds,0,arr,sum,n);
    return 0;
}