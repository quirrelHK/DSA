#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6;  // Denotes the accuracy (upto which decimal place)


// To find nth root of a number
double multiply(double mid, int n){
    double ans=1;
    for(int i=0;i<n;++i){
        ans*=mid;
    }
    return ans;
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    
    double lo = 0, hi = x, mid;

    while(hi - lo > eps){
        mid = lo + (hi-lo)/2;
        // if(mid*mid < x){
        //     lo=mid;
        // }
        if(multiply(mid,n) < x){
            lo = mid;   // mid is a possible answer so we include it
        }
        else{
            hi=mid;   // mid is a possible answer
        }
    }
    // Both low and high will give same result
    cout << setprecision(8) << "Hi: " << hi << endl << "Low: " << lo << endl;
    cout << pow(x, 1.0/n);

    // O(P*log(N*10^d))  -> p- multiply, 
}