// https://www.spoj.com/problems/EKO/
// We will use monotonic predicate function(either returns True or False)
// Use binary search to find the last height for which the function returns True

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n;  // no. of trees
long long m; // amount of wood required
long long trees[N];


bool isWoodSufficient(long long height){
    long long wood=0;
    for(int i=0;i<n;++i){
        if(trees[i]>=height){
            wood+= trees[i] - height;
        }
    }

    return wood >= m;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> trees[i];
    }

    long long lo = 0, hi = 1e9, mid;  // 1e9-> maximum height of trees
    while(hi - lo > 1){
        mid = lo + (hi-lo)/2;

        // T T T T F F F 
        if(isWoodSufficient(mid)){
            lo = mid;    // mid is a possible answer(like the last True)
        }
        else{
            hi=mid-1;   // mid cannot be a possible answer because it is False so we do not include it
        }
    }

    if(hi>=m){
        cout << "Maxi height: " << hi;
    }
    else{
        cout << "Maxi height: " << lo;
    }

    // O(Nlog(H))
}