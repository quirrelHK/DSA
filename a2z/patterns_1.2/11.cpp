/*
1 
0 1 
1 0 1
0 1 0 1 
1 0 1 0 1
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=3;
    for(int i=0;i<n;++i){
        for(int j=0;j<i+1;++j){
            if(i%2){
                if(j%2) cout << "1 ";
                else cout << "0 ";
            }
            else{
                if(j%2) cout << "0 ";
                else cout << "1 ";
            }
        }
        cout << endl;
    }
}