/*
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=5;
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j) cout <<"*";
        
        for(int k=2;k<2*(n-i);++k) cout <<" ";

        for(int j=0;j<=i;++j) cout <<"*";

        cout << endl;
    }
    for(int i=n-1;i>0;--i){
        for(int j=i;j>0;--j) cout <<"*";

        for(int k=2*i;k<2*n;++k) cout <<" ";
        
        for(int j=i;j>0;--j) cout<<"*";

        cout << endl;
    }

}