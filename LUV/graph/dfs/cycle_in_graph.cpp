

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> graph[N];
bool vis[N];

bool dfs(int vertex, int parent){
   
    vis[vertex]=true;
    bool isLoopExists = false;
    for(int child:graph[vertex]){
        if(vis[child] && child == parent) continue;
        if(vis[child]) return true;   // If we are visiting a child and it is not a parent then loop exists
        
        isLoopExists |=dfs(child,vertex);   // Some vertices will return false, if even a single loop exist then loop is there
                                            // and we return true. So, or operation is done.
    }
    return isLoopExists;
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bool isLoopExists = false;
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
    
        isLoopExists = dfs(i,-1);
        if(isLoopExists) break;
    }
    cout << isLoopExists << endl;

}