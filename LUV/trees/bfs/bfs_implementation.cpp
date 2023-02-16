// BFS is level order traversal.
// It gives shortest path between any two nodes using levels(only when weight of all edges are same), 
// the level of the node will be larger for larger path.
// So, that path is not taken.

// TC: O(V+E)
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
int vis[N];
int level[N]; // Stores the level of each node

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int cur_vertex = q.front();
        q.pop();
        cout << cur_vertex << " ";
        for(int child:g[cur_vertex]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_vertex]+1;
            }
        }
    }
}
int main(){
    int e;
    cin >> e;
    for(int i=0;i<e-1;++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);

    for(int i=1;i<=e;++i){
        cout << i << ":" << level[i] << endl;
    }

}