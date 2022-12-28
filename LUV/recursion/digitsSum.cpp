#include<bits/stdc++.h>
using namespace std;

int digitSum(int n){
    if(n==0) return 0;
    return digitSum(n/10) + n%10;

} // O(logN)

int main(){
    cout << digitSum(12345) << endl;
}