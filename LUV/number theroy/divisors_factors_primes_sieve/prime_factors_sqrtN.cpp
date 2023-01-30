#include<bits/stdc++.h>
using namespace std;

vector<int> prime_factors(int n){
    vector<int> primes;
    for(int i=2;i*i<=n;++i){     // We will difinitely get a prime number berfore sqrt(N) if the number is composite
        while(n%i==0){
            primes.push_back(i);
            n /= i;
        }
    }
    if(n>1){    // In case the number is prime we will not go inside the for loop so we simply take care of it here.
        primes.push_back(n);
    }
    return primes;
}

int main(){
    int n;
    cin >> n;
    vector<int> primes = prime_factors(n);
    for(auto &prime : primes){
        cout << prime << " ";
    }
    cout << endl;
}