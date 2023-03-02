// https://leetcode.com/problems/coin-change-ii/description/

// Instead for chossing all the possible coins in a level. We choose all the possilbe coins on a type at a level.
// Then at next level we choose all possible coins on another type
// i.e. If amount = 5; coins=[5,2,1] at level 1 we will choose one time 1, two time 2, ... five times 1.
// Then at next level for each branch say when we chose one time 1 (now amount = 4), we will choose one time 2 and two times 2 and so on for other branches and subsequent levels

#include<bits/stdc++.h>
using namespace std;
const int N=310;
const int M=1e3+10;
int coins[N];
int dp[N][M];

int solve(int ind, int amount){
    if(amount == 0) return 1;
    if(ind < 0) return 0;
    if(dp[ind][amount] != -1) return dp[ind][amount];
    int ways=0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind]){
        ways += solve(ind-1, amount-coin_amount);
    }

    return dp[ind][amount] = ways;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n,amount;
    cin >> n >> amount;
    for(int i=0;i<n;++i){
        cin >> coins[i];
    }

    cout << solve(n-1,amount) << endl;

}