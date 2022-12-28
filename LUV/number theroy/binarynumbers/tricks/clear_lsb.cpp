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
    printBinary(59);
    // 00000111011  (UNSET LSB 5th bit)
    // 11111100000 -> this number is required
    // 00000011111 -> inverse of the number above or (1<<5)-1
    int a=59;
    int i=4; // ith bit 0 to 4 (5bits)

    int b = (a & (~((1<<(i+1))-1)));
    printBinary(b);
}