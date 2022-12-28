#include<bits/stdc++.h>
using namespace std;

int knapSack(int C, int wt[], int val[], int n){
    int k[n+1][C+1];

    for(int i = 0;i<=n;++i){
        for(int w = 0; w <=C; ++w){
            if(i == 0 || w == 0){
                k[i][w] = 0;
            }
            else if(wt[i-1] <= w){
                k[i][w] = max(val[i-1] + k[i-1][w - wt[i-1]],k[i-1][w]);
            }
            else
                k[i][w] = k[i-1][w];
        }
    }
    return k[n][C];
}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int Capacity = 50;
    int n = sizeof(val)/sizeof(val[0]);

    cout << knapSack(Capacity,wt,val,n);
    return 0;
}