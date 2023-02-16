#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> graph[N];
int depth[N];

void dfs(int vertex, int parent=-1){

    for(int child: graph[vertex]){
        if(child==parent) continue;
        depth[child] = depth[vertex]+1;
        dfs(child,vertex);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    int max_depth=-1;
    int max_depth_node;
    for(int i=1;i<=n;++i){
        if(max_depth < depth[i]){
            max_depth=depth[i];
            max_depth_node=i;
        }
        depth[i]=0;  // Because we have to again calculate depth of the tree with max_depth_node as root node

    }
    max_depth=-1;
    dfs(max_depth_node);
    for(int i=1;i<=n;++i){
        if(max_depth < depth[i]){
            max_depth=depth[i];
        }
    }

    cout << max_depth << endl;


}