// Subtree- computation is from leaf to root

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> graph[N];

/*
Given Q queries, Q <= 10^5
In each query given V,
print subtree sum of V, number of even numbers 
in subtree of V
*/
vector<int> subtree_sum(N,0);
vector<int> even_cnt(N,0);

void dfs(int vertex, int parent=-1){

    if(vertex%2==0) even_cnt[vertex] +=1;

    subtree_sum[vertex]+=vertex;
    for(int child: graph[vertex]){
        if(child == parent) continue;

        dfs(child,vertex);

        subtree_sum[vertex]+=subtree_sum[child];
        even_cnt[vertex]+=even_cnt[child];
    }
}

void dfs2(int vertex,int parent=-1){

    subtree_sum[vertex]+=vertex;
    if(graph[vertex].size() == 1) return;
    for(int child: graph[vertex]){
        if(child == parent) continue;

        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
    }
}
int main(){

    int E;
    cin >> E;
    for(int i=0;i<E-1;++i){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // dfs(1);


    // for(int i=1;i<=E;++i){
    //     cout << subtree_sum[i] << " " << even_cnt[i] << endl;
    // }
    cout << graph[5].size() << endl;
    int q;
    cin >> q;
    while(q--){
        int V,U;
        cin >> V >> U;
        dfs2(V,U);
        cout << subtree_sum[V] << " " << even_cnt[V] << endl;
    }
}