#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;  // Sometimes might not work of N = 1e7
vector<vector<int>> divisors(N);
int main(){
    for(int i=2;i<=N;++i){
        for(int j=i;j<=N;j+=i){
            divisors[j].push_back(i);
        }
    } // O(N * log(N))
    
    for(int i=0;i<100;++i){
        for(int j=0;j<divisors[i].size();++j){
            cout << divisors[i][j] << " ";
        }
        cout << endl;
    }
}