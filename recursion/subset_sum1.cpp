// Print sum of all subsets in a list. Output should be printed in decreasing order

#include<bits/stdc++.h>
using namespace std;

void sum_subset(int ind, int sum, vector<int> &ans, vector<int> arr){
    if(ind == arr.size()){
        ans.push_back(sum);   // pushing the sum to ans after reaching the base case
        return;
    }

    sum_subset(ind+1,sum+arr[ind],ans,arr);  // picking the element in the current index

    sum_subset(ind+1,sum,ans,arr); // not picking the element in the current index

}


int main(){
    vector<int> arr = {3,1,2};
    vector<int> ans;
    

    sum_subset(0,0,ans,arr);
    sort(ans.begin(),ans.end());
    for(auto it : ans){
        cout << it << " ";
    }
}