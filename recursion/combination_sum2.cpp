#include<bits/stdc++.h>
using namespace std;

void combination(int ind, vector<int> &ds, int target, vector<int> arr, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
    int i;

        for(i = ind; i < arr.size(); ++i){
            if(i > ind && arr[i-1] == arr[i]) continue;
            if(arr[i] > target) break;

            ds.push_back(arr[i]);
            combination(i+1,ds,target-arr[i],arr,ans); 
            ds.pop_back();
        }
}

int main(){

    vector<int> arr = {10,1,2,7,6,1,5,8};
    vector<int> ds;
    vector<vector<int>> ans;
    int target = 8;
    int n = arr.size();
    sort(arr.begin(),arr.end());
    combination(0,ds,target,arr,ans);

    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}