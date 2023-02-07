#include<bits/stdc++.h>
using namespace std;


void optimized_factors(int n){
    int cnt=0,sum=0;
    for(int i=1; i*i <= n;++i){   // i=1;i<=sqrt(n);++i
            if(n%i == 0){
            cout << i << " " << n/i << endl;
            cnt += 1;
            sum += i;
            if(i != n/i){
                cnt+=1;
                sum+=n/i;
            }
        }
    }
    cout << cnt << " " << sum << endl;
}
int main(){

    int n;
    cin >> n;
    optimized_factors(n);
    return 0;
}