// print all possible subset in any order. The solution set must not contain duplicate subsets.

#include<bits/stdc++.h>
using namespace std;

void subset_sum(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> arr){
    ans.push_back(ds);
    for(int i = ind; i < arr.size(); ++i){
        if(ind != i && arr[i] == arr[i-1]) continue;
        
        ds.push_back(arr[i]);
        subset_sum(i+1,ds,ans,arr);
        ds.pop_back();
    }
}

int main(){
    vector<int> arr = {1, 4, 7, 8};
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());  // to check for duplicates
    subset_sum(0,ds,ans,arr);
    cout << ans.size() << endl;
    // for(int i = 0; i < ans.size(); ++i){
    //         for(int j = 0; j < ans[i].size(); ++j){
    //             cout << ans[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // int n = ans.size();
    
    // set<vector<int>> st(ans.begin(),ans.end());

    // if (n == st.size()){
    //     cout << "\nYes";
    // }
}