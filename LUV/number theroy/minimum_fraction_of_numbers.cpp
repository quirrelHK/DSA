/*
Mini. fractions:
12/18 == 2/3
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int x,y;
    cin >> x >> y;
    cout << x <<"/"<<y<< " == " << x/__gcd(x,y) << "/" << y/__gcd(x,y) << endl;
}