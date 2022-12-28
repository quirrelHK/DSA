// Euclid's algorithm uses long division to find GCD
/*
LCM(X,Y) = (X*Y)/GCD(X,Y)
*/

#include<bits/stdc++.h>
using namespace std;


int gcd(int dividend, int divisor){
    if(divisor == 0) return dividend;

    return gcd(divisor, dividend%divisor);
}

int main(){
    cout << gcd(18,12) << endl;
    cout << gcd(12,18) << endl; // Order of numbers does not matter
    cout << gcd(12,4) << endl;

    cout << 12*18 / gcd(12,18) << endl;
}