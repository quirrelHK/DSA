// https://leetcode.com/problems/network-delay-time/

/*
It is used for weighted graphs
It is a single source multiple destination algorithm; we have to calculate distance of source for each node

For optimized code we use priority queue(we can use multiset instead because it is less complex; here set will suffice)
TC: O(V+ElogV)
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;

// vector<pair<int,int>> g[N];

int dijkstra(int source, vector<pair<int,int>> g[], int n){
    vector<int> vis(N,0);
    vector<int> dist(N,INF);

    set<pair<int,int>> q;  // {distance,node}
    q.insert({0,source});
    dist[source]=0;

    while(q.size()>0){
        auto node = *q.begin();
        int v = node.second;
        int dis = node.first;
        q.erase(q.begin());
        if(vis[v]==1) continue;   // If the node is poped from they we do not process it again
        vis[v]=1;

        for(auto &child:g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                q.insert({dist[child_v],child_v});
            }
        }
    }
    int maxx=0;
    for(int i=1;i<=n;++i){
        if(dist[i]==INF) return -1;
        maxx = max(maxx,dist[i]);
    }
    return maxx;

}
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> g[N];
        for(auto vec:times){
            g[vec[0]].push_back({vec[1],vec[2]});
        }
}

int main(){
    int n,m;
    cin >> n >> m;
    // for(int i=0;i<m;++i){
    //     int x,y,wt;
    //     cin >> x >> y >> wt;
    //     g[x].push_back({y,wt});
    // }
}