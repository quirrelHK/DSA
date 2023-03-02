// https://atcoder.jp/contests/dp/tasks/dp_e

/*
Here the W~1e9. So, we cannot use the previous code becuase it will result in TLE
We will sum all the values(1 to N) and then we will chose minimize the weights the for every value.
Then value for the weigth which is <= to the capacity of bag will be the answer. 

Instead of maximizing the value for each wight_left, we minimize the weight is order the achieve that value.
Here all possible values, and so the values for which calculated weights is <= capacity is the answer.
*/
#include<bits/stdc++.h>
using namespace std;
int wt[105],val[105];

long long dp[105][100005];

long long func(int ind, int val_left){
    if(val_left == 0) return 0;
    if(ind < 0) return 1e15;  // when all values are exhausted, return minimum weight. Since min. weight does not exists we return a large value
    if(dp[ind][val_left] != -1) return dp[ind][val_left];
    
    long long ans = func(ind-1,val_left);

    if(val_left-val[ind] >= 0)
        ans = min(ans, func(ind-1,val_left-val[ind]) + wt[ind]);

    return dp[ind][val_left] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));

    int n,w;
    cin >> n >> w;
    for(int i=0;i<n;++i){
        cin >> wt[i] >> val[i];
    }

    int max_val = 1e5;
    for(int i=max_val; i>=0;--i){
        if(func(n-1,i) <= w){
            cout << i << endl;
            break;
        }
        
    }


}