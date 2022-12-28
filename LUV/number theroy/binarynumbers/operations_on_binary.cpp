#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10; i>=0;--i){
        cout << ((num >>  i) & 1);
    }
    cout << endl;
}
int main(){
    // Check if ith bit is SET
    int a  = 9;
    int i = 1;
    if((a & (1<<i) ) != 0){
        cout << "Set bit" << endl;
    }
    else{
        cout << "UNset bit" << endl;
    }

    printBinary(a);

    // Set ith bit
    printBinary( a | (1<<i));    // Oring with ith bit set

    // Unset ith bit
    printBinary(a & ~(1 << i));  // Anding with all bit set expect ith bit

    // Toggle ith bit
    printBinary(a ^ (1<<i));
    printBinary(a ^ (1<<4));

    // Count number of SET bit
    int cnt=0;
    for(int i=31;i>=0;--i){
        if( (a >> i) & 1){
            cnt++;
        }
    }
    cout << cnt << endl;

    // Built-in function to count SET bit
    cout << __builtin_popcount(a) << endl;
    cout << __builtin_popcountll((1LL<<34) -1) << endl; // For long long type



}