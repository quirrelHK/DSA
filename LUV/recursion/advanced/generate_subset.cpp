// Leetcode
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
void generate(vector<int> &nums, int ind, vector<int> &ds){
    if(ind==nums.size()){
        res.push_back(ds);
        return;
    }

    // not picking ith element
    generate(nums,ind+1,ds);

    // picking ith element
    ds.push_back(nums[ind]);
    generate(nums,ind+1,ds);
    ds.pop_back();
}

int main(){

    int n=3;
    vector<int> nums(n);
    for(int i=0;i<n;++i){
        nums[i]=i+1;
    }

    vector<int> ds;
    generate(nums,0,ds);

    for(auto &subset: res){
        for(auto &val: subset){
            cout << val << " ";
        }
        cout << endl;
    }

}//O(2^n)