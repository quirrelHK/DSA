// Taylor's method 

#include <bits/stdc++.h>
using namespace std;
int main(){
    double n=4,x0,y0,x;
    cout<<"Enter x0 : ";
    cin>>x0;
    cout<<"Enter y0 : ";
    cin>>y0;
    cout<<"Enter x : ";
    cin>>x;
    vector<double> data(n,0);
    data[0] = y0;
    data[1] = x0-y0*y0;
    data[2] = 1 - 2*y0*data[1]; 
    data[3] = -2*(y0*data[2] + data[1]*data[1]);
    double ans = 0;
    double temp=1,fact=1;
    for(int i=0; i<n; i++){
        ans += (temp*data[i])/fact;
        temp *= (x-x0);
        fact = fact*(i+1);
    }
    cout<<"Using Taylor's method : "<<ans<<endl;
    return 0;
}