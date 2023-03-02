// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

#include<bits/stdc++.h>
using namespace std;

int dp[1010];
int func(int len, vector<int> &prices){

    if(len == 0) return 0;
    if(dp[len] != -1) return dp[len];
    int ans=0;
    for(int len_to_cut=1;len_to_cut<=prices.size();++len_to_cut){
        if(len-len_to_cut >=0){
            ans = max(ans, func(len-len_to_cut,prices) + prices[len_to_cut-1]);
        }
    }

    return dp[len] = ans;
}

int main(){

    memset(dp, -1, sizeof(dp));
    int n,len;
    cin >> n;
    vector<int> prices(n,0);
    for(int i=0;i<n;++i){
        cin >> prices[i];
    }

    cout << func(n,prices) << endl;
}