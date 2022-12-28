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
    
    double first = data[0][1]+data[n][1];
    double ans_by_3 ,ans_by_8;
    ans_by_3 = ans_by_8 = first;
    double a=0,b=0;
    for(int i=1;i<=n-1;++i){
        if(i%2){
            a += data[i][1];
        }
        else{
            b+=data[i][1];
        }
    }

    ans_by_3 = ans_by_3 + 4*(a) + 2*(b);
    ans_by_3 = (h/3.0)*ans_by_3;
    
    a = b = 0;
    for(int i=1;i<=n-1;++i){
        if(i%3==0){
            b += data[i][1];
        }
        else{
            a+=data[i][1];
        }
    }
    ans_by_8 = ans_by_8 + 3*(a) + 2*(b);
    ans_by_8 = ((3*h)/8.0)*ans_by_8;

    cout << "Using Simpson's 1/3: " << ans_by_3 << endl;
    cout << "Using Simpson's 3/8: " << ans_by_8 << endl;
    return 0;
}