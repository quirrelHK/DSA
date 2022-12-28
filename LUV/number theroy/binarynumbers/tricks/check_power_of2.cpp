// Clear LSB upto ith bit
#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10; i>=0;--i){
        cout << ((num >>  i) & 1);
    }
    cout << endl;
}
int main(){
    int n =16;
    printBinary(n);
    // If a number is a power of 2 it has only one SET bit
    // Here 00000010000
    //      00000001111  Anding of these would result in zero
    if(n & (n-1)){ // IF not zero
        cout << "Not a power of 2" << endl;
    }
    else{
        cout << "power of 2" << endl;
    }
}