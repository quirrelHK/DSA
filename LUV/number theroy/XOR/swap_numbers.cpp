#include<bits/stdc++.h>
using namespace std;

// XOR of same bit = 0
// XOR of 0 and 1 = 1
// XOR of any number x with 0 = the number x
int main(){
    int a = 4, b = 6;

    a = a ^ b;
    b = b ^ a;   // b <--- a
    // b = b ^ (a ^ b) --> b ^ b ^ a (associativity property of XOR):- A ^ B ^ C == B ^ A ^ C == C ^ B ^ A
    
    a = a ^ b; // a <--- b
    // a = (a ^ b) ^ a --> a ^ a ^ b

    cout << a << " " << b << endl;

}