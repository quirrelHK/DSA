#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int start, int end, string s){
    while(start<=end){
        if(s[start++] != s[end--]) return false;
    }
    return true;
}

void partition(int ind, vector<string> &ds, vector<vector<string>> &ans, string s){
    if(ind == s.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = ind; i < s.size(); ++i){
        if(isPalindrome(ind,i,s)){
            ds.push_back(s.substr(ind,i-ind+1));

            partition(i+1,ds,ans,s);
            ds.pop_back();

        }
    }
}




int main(){
    string s = "bbaabb";
    vector<string> ds;
    vector<vector<string>> ans;

    partition(0,ds,ans,s);

  for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}