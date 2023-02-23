/*
All pair shortest path algorithm. Interger 'k' is used to for allowing no. of levels or no. of nodes.
Ex: For dist between u to v at k = 0 would simply be the direct distance from u t0 v
    But is k=1 then dist u to v may be u->anyNode->v
    for k=2 u->node1->node2->v. Similary for other levels or nodes
    then if we know dist[u][v] then the distance via any k node will be dist[i][k]+dist[k][v]

***************
1. This algo can handle negative weights
2. Cannot handle negative weighted cycle  (the distance will keep on decreasing as traverse the cycle)
***************

O(N^3)
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9+7;

int dist[N][N];

int main(){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(i==j) 
                dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    }
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int x,y,wt;
        cin >> x >> y >> wt;
        dist[x][y]=wt;
    }

    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(dist[i][j]==INF)
                cout << "I ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

}