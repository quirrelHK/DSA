// extra space o(n)
#include<bits/stdc++.h>
using namespace std;

void permutations(vector<int> &ds,  vector<vector<int>> &ans, int freq[], vector<int> arr){
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < arr.size(); ++i){
        if(!freq[i]){
            freq[i]=1;
            ds.push_back(arr[i]);
            permutations(ds,ans,freq,arr);
            freq[i]=0;
            ds.pop_back();
        }
    }
}

int main(){
    vector<int> arr = {1,1,2};
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()] = {0};
    
    permutations(ds,ans,freq,arr);
    
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
