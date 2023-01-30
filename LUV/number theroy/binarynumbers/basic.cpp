#include<bits/stdc++.h>
using namespace std;


int main(){
    cout << INT_MAX << endl;

    // int a = (1<<32) - 1;   // Warning because 1 is of type int also   total 33 bits are there but int only has 32
    int a = (1LL<<32) - 1;
    
    cout << a << endl;   // Overflow(because 1 bit is reserved for sign)
    int b = (1LL<<31) -1;
    cout << b << endl;

    unsigned int c=(1LL<<32)-1; 
    cout << c << endl;   // NO sign bit so does not overflows for 32 bit
}