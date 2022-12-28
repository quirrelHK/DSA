// Implementation of Weddle's method
#include<bits/stdc++.h>

#define f(x) pow((1+x*x),-1)
using namespace std;

int main(){
    int n;
    cin >> n;
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
    double ans= (data[0][1]+data[n][1]);
    for(int i=1;i<=n-1;++i){
        if(( i%6== 1) || (i%6 == 5)){
            ans += 5*data[i][1];
        }
        else if((i%6==2) || (i%6 == 4)){
            ans += data[i][1];
        }
        else if(i%6 == 3){
            ans += 6*data[i][1];
        }
        else{
            ans += 2*data[i][1];
        }
    }
    ans *= (3*h)/10.0;
    cout << "Using Weddle's method: " << ans << endl;
    
    
    return 0;
}