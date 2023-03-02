// https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int wt[105],val[105];
long long dp[105][100005];

long long func(int ind, int wt_left){
    if(wt_left == 0) return 0; // Bag is full
    if(ind < 0) return 0;    // All items are exhausted but still some space is left in knapsack
    if(dp[ind][wt_left] != -1) return dp[ind][wt_left];

    // Not Pick at ind
    long long ans = func(ind-1,wt_left);
    // Pick item as ind
    if(wt_left - wt[ind]>=0)
        ans = max(ans,func(ind-1,wt_left-wt[ind]) + val[ind]);

    return dp[ind][wt_left] = ans;
}//O(N*W) ~ 10^7

int main(){
    memset(dp, -1, sizeof(dp));
    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;++i){
        cin >> wt[i] >> val[i];
    }
    cout << func(n-1,w) << endl;
}