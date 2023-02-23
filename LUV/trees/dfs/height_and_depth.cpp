// Height: distance of a node from the farthest leaf node
// Depth: distance of a node from root node

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> tree[N];
int depth[N],height[N];

// Here we can just use parent to avoid going to visited nodes
void dfs(int node, int parent=0){
    
    for(int child:tree[node]){
        if(child == parent) continue;
        depth[child] = depth[parent]+1;
        dfs(child,node);
        height[node] = max(height[node],height[child]+1);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;++i){   // n is the number of nodes; there are n-1 edges in a tree with n nodes
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }


    dfs(1);

    
    for(int i=1;i<=n;++i){
        cout << depth[i] << " " << height[i] << endl;
    }
}