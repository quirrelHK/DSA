// Eular's method
#include<bits/stdc++.h>
// #define f(x,y) 3*x+4*y
// #define f(x,y) x*x*x*(exp(-2*x)) - 2*y
#define f(x,y) -2*y*y+x*y+x*x
using namespace std;
int main(){
    double n,x0,y0,x,h;
    cout<<"Enter x0 : ";
    cin>>x0;
    cout<<"Enter y0 : ";
    cin>>y0;
    cout<<"Enter x : ";
    cin>>x;
    cout<<"Enter the value of h : ";
    cin>>h;
    //h = (x-x0)/n
    n = x/h;


    double ansx = x0,ansy = y0;
    for(int i=0;i<n; i++){
        ansy = ansy + h * (f(ansx,ansy));
        ansx = ansx+h;
    }
    cout<<"Using Eular's method : "<<ansy<<endl;

    return 0;
    
}