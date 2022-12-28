#include<bits/stdc++.h>
using namespace std;

/*
Given array a of n integers. All integers are present in even count expect one.
Find that one integer which has odd count in O(N) time complexity and O(1) space.

N < 10^6
a[i] < 10^5
*/

int main(){
    // Taking xor of all elements even elements will cancel out with each other. Only the odd element will remain.

    int n;
    cin >> n;
    int x;
    int ans=0;
    for(int i=0;i<n;++i){
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
}