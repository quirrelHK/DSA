#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> find_subsets(vector<int> &nums){
    int n=nums.size();
    int subset_cnt = (1<<n); // 2^n
    vector<vector<int>> subsets;
    for(int mask = 0;mask < subset_cnt;++mask){
        vector<int> subset;
        for(int i = 0;i<n;++i){
            // Check if ith bit in mask is set

            if((mask & (1<<i)) != 0){
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }

    return subsets;
}//O(n * 2^n)

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }

    auto all_subsets = find_subsets(v);

    for(auto &subset : all_subsets){
        for(auto &element : subset){
            cout << element << " ";
        }
        cout << endl;
    }
 
}