// LCA is the common ancestor for any two nodes; that ancestor being lowest i.e. first ancestor of the two nodes that is common

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> graph[N];
int parent[N];  // Stores the parent of ith node

void dfs(int v, int p=-1){
    parent[v]=p;
    for(int child:graph[v]){
        if(child == p) continue;

        dfs(child,v);
    }
}

vector<int> path(int v){  // Path of node v from root node
    vector<int> ans;
    while(v!=-1){
        ans.push_back(v);
        v=parent[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// We will store the path of the two nodes from the root node in two arrays
// Then the last node that is common in both the arrays will be the LCA
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

    int node1,node2;
    cin >> node1 >> node2;
    vector<int> path_node1 = path(node1);
    vector<int> path_node2 = path(node2);
    
    int min_len = min(path_node1.size(),path_node2.size());

    int lca=-1;
    for(int i=0;i<min_len;++i){
        if(path_node1[i] == path_node2[i])
            lca = path_node1[i];
        else 
            break;
    }

    cout << lca << endl;

}//O(N)