#include<bits/stdc++.h>
using namespace std;

void func1(int n){
    if(n==0) return;
    cout << n << endl;
    func1(n-1);
} // 5 4 3 2 1

void func2(int n){
    if(n==0) return;
    func2(n-1);
    cout << n << endl;
} // 1 2 3 4 5
int main(){
    func1(5);
    cout << endl;
    func2(5);

}