/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=5;
    for(int i=0;i<n;++i){
        for(int j=n;j>i;--j){
            cout <<"*";
        }
        for(int k=0;k<2*i;++k){
            cout << " ";
        }
        for(int j=n;j>i;--j){
            cout << "*";
        }
        cout << endl;
    }
    for(int i=n;i>0;--i){
        for(int j=n;j>=i;--j){
            cout <<"*";
        }
        for(int k=2;k<2*i;++k){
            cout<<" ";
        }
        for(int j=n;j>=i;--j){
            cout<<"*";
        }
        cout<<endl;
    }
}