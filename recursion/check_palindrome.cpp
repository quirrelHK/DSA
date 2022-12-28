#include<iostream>
using namespace std;

bool palin(string s, int i , int n){
    if(i >= n/2) return true;

    if(s[i] != s[n-i-1]) return false;
    return palin(s,i+1,n);
}

int main(){
    string strs = "madamm";
    
    cout << palin(strs,0,strs.length());
}