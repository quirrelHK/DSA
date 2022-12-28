// Print linearly from 1 to n using backtracking
#include<iostream>
using namespace std;

void fun(int i,int n){
    if(i < 1)
        return;

    fun(i-1,n);       // after base condition the last function will be executed i.e. fun(1,n) print statement first
    cout << i << endl;   
}

int main(){
    int n;
    cin >> n;
    fun(n,n);
}