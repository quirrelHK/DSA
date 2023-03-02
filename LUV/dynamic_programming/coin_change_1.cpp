// https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;

int coins[15];
int dp[N];

int coinChange(int amount, int n){
    if(amount == 0) return 0;
    if(dp[amount] != -1) return dp[amount];
    int ans=INT_MAX;
    for(int i=0;i<n;++i){
        if(amount-coins[i] >= 0)
            ans = min(ans + 0LL, coinChange(amount-coins[i],n) + 1LL);    // + 1LL because (INT_MAX + 1) value overflows; + 0LL becuase min only allows same data types
    }

    return dp[amount] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));

    int n,amount;
    cin >> n >> amount;
    for(int i=0;i<n;++i){
        cin >> coins[i];
    }

    int ans = coinChange(amount,n);
    cout << (ans==INT_MAX ? -1 : ans)<< endl;
}