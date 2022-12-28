/*
E
E D
E D C
E D C B
E D C B A
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=5;
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            cout << (char)((65+n-1)-j) << " ";
        }
        cout << endl;
    }
}