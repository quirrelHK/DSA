#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int dp[N];

//**********************
// Top down approach: Use larger problem to solver smaller problem; here we are calculating (n-1) using (n)

int fib(int n){      // n-> current state of dp (which problem you could say or the parameters that are changing each time you call the function)
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n] != -1) return dp[n];  // Memoise operation

    return dp[n] = fib(n-1) + fib(n-2);   // Assign solution to nth state and return it
}// TC: O(N)

int main(){

    int n=6;

    // We fill the dp array with a value that is not part of the solution to signify that that solution have not been 
    // calculated yet.
    for(int i=0;i<=n;++i){
        dp[i]=-1;
    }
    
    cout << fib(n) << endl;

    // ********************
    // Bottom up approach: Use smaller problems to come up with the solution to larger problems
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[n] << endl;

}