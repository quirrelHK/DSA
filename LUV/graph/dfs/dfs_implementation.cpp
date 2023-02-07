// https://visualgo.net/en/dfsbfs

// TC:O(V+E)
#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> graph[N];
bool vis[N];

void dfs_boiler_plate(int vertex){
    vis[vertex]=true;
    for(int child:graph[vertex]){
        if(vis[child]) continue;
        
        dfs(child);
    }
}

void dfs(int vertex){
    /**
     * Take action after entering the vertex
    */

    // cout << vertex << endl;
    vis[vertex]=true;
    for(int child:graph[vertex]){
        /**
         * Action before entering the child node
        */

        // cout << "P:" << vertex << " C:" << child << endl;
        if(vis[child]) continue;


        dfs(child);
        /**
         * Take action on child after entering child node
        */
    }
    /**
     * Take action on vertex before exiting the vertex
    */
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

    dfs(1);

}