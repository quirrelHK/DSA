/*
ABCDE
ABCD
ABC
AB
A
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=5;
    for(int i=n;i>0;--i){
        for(int j=65; j<65+i;++j){
            cout << (char)j;
        }
        cout << endl;
    }
}