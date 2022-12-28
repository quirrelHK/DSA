// https://www.spoj.com/problems/AGGRCOW/
// main task is to define the predicate function

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,cows;
int stallPositions[N];

bool canPlaceCows(int minDist){
    int lastPos=-1;
    int cows_cnt = cows;
    for(int i=0;i<n;++i){
        if(lastPos==-1 || stallPositions[i] - lastPos >= minDist){
            cows_cnt--;
            lastPos = stallPositions[i];
        }
        if(cows_cnt==0) break;
    }

    return cows_cnt==0;
}
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> cows;
        for(int i=0;i<n;++i){
            cin >> stallPositions[i];
        }

        sort(stallPositions,stallPositions+n);

        // T T T T T T F F F F  (T-> we can palce 'cows' with mini. distance minDist. F-> we cannot place them as such)
        int lo=0, hi = 1e9, mid;

        while(hi - lo > 1){
            mid = lo + (hi-lo)/2;
            if(canPlaceCows(mid)){
                lo=mid; 
            }
            else{
                hi = mid-1;
            }
        }

        if(canPlaceCows(hi)){
            cout << "Max minimum dist: " << hi << endl;
        }
        else{
            cout << "Max minimum dist: " << lo << endl;
        }
    }

    // O(Nlog(10^9))
    
}