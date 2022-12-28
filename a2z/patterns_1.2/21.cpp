/*
*****
*   *
*   *
*   *
*****
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=5;
    for(int i=0;i<n;++i){
        if(i==0 || i==n-1)
            for(int j=0;j<n;++j) cout <<"*";
        else{
            cout<<"*";
            for(int j=2;j<n;++j) cout <<" ";
            cout <<"*";
        }
        cout <<endl;
    }
}