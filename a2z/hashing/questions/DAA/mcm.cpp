#include<bits/stdc++.h>
using namespace std;
const int n = 100;
int dp[n][n];

int MCM(int *p, int i, int j){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;

    for(int k = i;k < j; ++k){
        dp[i][j] = min(dp[i][j], MCM(p,i,k) + MCM(p,k+1,j) + p[i-1]*p[k]*p[j]);
    }
    return dp[i][j];
}

int main(){
    int P[] = {10,20,30,40};
    int n = sizeof(P)/sizeof(P[0]);
    // memset(dp,-1,sizeof(dp));
    for(int i = 0;i<n;++i){
        for(int j =0;j<n;++j){
            dp[i][j] = -1;
        }
    }
    cout << MCM(P,1,n-1);
}

