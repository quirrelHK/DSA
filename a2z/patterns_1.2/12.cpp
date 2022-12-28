/*
1                 1
1 2             2 1
1 2 3         3 2 1
1 2 3 4     4 3 2 1
1 2 3 4 5 5 4 3 2 1
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=9;
    int k=4*n-4;
    for(int i=0;i<n;++i){
        for(int j=1;j<=i+1;++j){
            cout << j << " ";
        }
        while(k--){
            cout <<" ";
        }
        k = (4*n-4) - 4*(i+1);
        for(int j=i+1;j>=1;--j){
            cout << j << " ";
        }
        cout << endl;
    }
}