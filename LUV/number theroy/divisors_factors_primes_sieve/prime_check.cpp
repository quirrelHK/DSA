#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n){
    if(n==1) return true;

    for(int i=2;i*i<=n;++i){
        if(n%i==0) return false;
    }
    return true;
}
int main(){

    cout << is_prime(36) << endl;
    cout << is_prime(23) << endl;

}