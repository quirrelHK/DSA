/*
A
AB
ABC
ABCD
ABCDE
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=5;
    for(int i=0;i<n;++i){
        for(int j=65;j<=65+i;++j){
            cout << (char)j;
        }
        cout << endl;
    }
}