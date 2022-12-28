/*
Given 2d array a of N*N intergers. Given Q queries and in each query
given a, b, c and d print sum of the quadilateral represented by (a,b)
as top left point and (c,d) as bottom right point

Constraints
1 <= Q <= 10^5
1 <= N <= 10^3
1 <= a[i][j] <= 10^9
1 <= a,b,c,d <=N
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n+1][n+1];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            cin >> arr[i][j];
    }
    int pf_sum[n+1][n+1]={0};
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            pf_sum[i][j] = arr[i][j]+pf_sum[i-1][j]+pf_sum[i][j-1]-pf_sum[i-1][j-1];
        }
    }
    int q;
    cin >>q;
    while (q--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << pf_sum[c][d]-pf_sum[a-1][d]-pf_sum[c][b-1]+pf_sum[a-1][b-1] << endl; 
    }
       
}