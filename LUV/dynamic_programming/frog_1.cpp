// https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int dp[N];
int height[N];

int solve(int i){
    if(i==0) return 0;
    if(dp[i] != -1) return dp[i];
    int cost = INT_MAX;
    // Way 1 of reaching ith stone
    cost = min(cost, solve(i-1) + abs(height[i]-height[i-1]));

    // Way 2 of reaching ith stone
    if(i>1)
    cost = min(cost, solve(i-2) + abs(height[i]-height[i-2]));

    return dp[i] = cost;
}

int main(){

    // memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> height[i];
    }
    
    // cout << solve(n-1) << endl; 



    /* 
        Iterative solution
    */
    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);
    int cost = INT_MAX;

    for(int i=2;i<n;++i){
        cost = min(dp[i-2] + abs(height[i]-height[i-2]), dp[i-1]+abs(height[i]-height[i-1]));
        dp[i] = cost;
    } 
    // cout << endl;


    cout << dp[n-1] << endl;
}