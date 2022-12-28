#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int binExpRecur(int a, int b){

    if(b == 0) return 1;

    int res = binExpRecur(a,b/2);
    if(b&1){
        return (a * (res * 1LL * res) %M ) % M;
    }
    else{
        return (res * 1LL *res)%M;
    }
} // O(log(b))

int binExpItr(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1){ // if LSB is SET
            res = (res * 1LL * a)%M;
        }
        a = (a * 1LL * a)%M;
        b = b >> 1;
    }

    return res;
}// O(log(b))

int main(){
    
    /*
    double number = 1e24;
    cout << setprecision(20) << number << endl;
    int a = 2, b = 13;
    int ans=1;
    for(int i=0;i<b;++i){
        ans *=a;
    }//O(N )
    cout << ans << endl;
    */
    cout << binExpRecur(2,10) << endl;
    cout << binExpItr(10,13) << endl;
    cout << pow(2,10) << endl;

}