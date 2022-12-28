#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10; i>=0;--i){
        cout << ((num >>  i) & 1);
    }
    cout << endl;
}
int main(){
    for(char c = 'A'; c<='E'; ++c){ 
        cout << c << endl;
        printBinary(int(c));   // 5th bit is UNset
    }

    for(char c = 'a'; c<='e'; ++c){
        cout << c << endl;
        printBinary(int(c));    // 5th bit is SET
    }

    char A = 'a';
    char a = A | 1<<5;  // SET 5th bit
    cout << a << endl;

    cout << char(a & ~(1<<5)) << endl; // UNSET 5th bit


    // SOME NEAT TRICk
    cout << char(1<<5) << endl; // This is acutally whitespace(TO UPPER)
    
    // FOR LOWER we only require 00001011111 (instead of 11111011111)
    // 00001011111-> UNDERSCORE

    cout << char('C' | int(' ')) << endl;

    cout << char('c' & int('_')) << endl;

}