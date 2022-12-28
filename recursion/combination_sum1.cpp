// Given an array and target return a list of combination of elements whose sum is equal to target
#include<bits/stdc++.h>
using namespace std;

void combination_sum(int ind, vector<int> &ds, int target, vector<vector<int>> &ans, vector<int> arr){
    if(ind == arr.size()){
        if(target == 0){
            ans.push_back(ds);  // add that combination to the ans
        }
        return;
    }

    // pcik up the element; index does not change
    if(arr[ind] <= target){
        ds.push_back(arr[ind]) ;
        combination_sum(ind,ds,target-arr[ind],ans,arr);
        ds.pop_back();  // Once we completed the left recursion we have to remove the last element because it would mess up with the next combination
        
    }

    // not pick the element; move to next index
    combination_sum(ind+1,ds,target,ans,arr);
}

int main(){

    vector<int> arr = {1,1,1,2,2};
    // int n = arr.size();
    int target = 7;

    vector<vector<int>> ans;
    vector<int> ds;

    combination_sum(0,ds,target,ans,arr);

    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}