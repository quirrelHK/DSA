/*
   A
  ABA
 ABCBA
ABCDCBA
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=5;
    for(int i=0;i<n;++i){
        for(int k=0;k<n-(i+1);++k){
            cout << " ";
        }
        for(int j=65;j<=65+i;++j){
            cout << (char)j;
        }
        if(i>=1){
            for(int j=i-1;j>=0;--j){
                cout << (char)(65+j);
            }
        }
        cout << endl;
    }
}