#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int graph1[N][N];
vector<pair<int, int>> graph2[N];    // Each vector has a list of size N
int main(){
    int n,m;
    cin >> n >>m;
    for(int i=0;i<m;++i){
        int v1,v2,wt;
        cin >> v1 >> v2 >> wt;
        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt;
        graph2[v1].push_back({v2,wt});
        graph2[v2].push_back({v1,wt});
    }

}

/*
 1. When we want to find if 2 vertices are connected or weights associated;
    in adj. matrix we can do this in O(1), 
    if(graph1[i][2] == 1){
        // connected
    }
    
    but in adj. list we have to check for each connected node(O(V))
    for(auto child : graph2[i]){
        if(child == j){
            // connected
        }
    }
*/

