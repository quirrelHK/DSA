#include<bits/stdc++.h>

#define f(x) pow((1+x*x),-1)
using namespace std;


int main(){
    int n=6;
    vector<vector<double>> data(n+1,vector<double>(2,0));
    double limit_up, limit_down;
    cin >> limit_up >> limit_down;
    double h = (limit_up-limit_down)/(double)n;
    
    data[0][0] = limit_down;
    data[0][1] = f(data[0][0]);
    for(int i=1;i<=n;++i){
        data[i][0] = data[i-1][0]+h;
        data[i][1] = f(data[i][0]);
    }
    

    double val = (data[0][1]+data[n][1])/(double)2;
    for(int i=1;i<=n-1;++i){
        val+= data[i][1];
    }

    cout << "Ans: " << h*val;
    return 0;
}