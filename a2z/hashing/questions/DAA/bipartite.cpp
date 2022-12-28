#include<bits/stdc++.h>
using namespace std;

void addE(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isBipartite(vector<int> adj[], int u, vector<bool> visited, vector<int> color){
    for(int i :adj[u]){
        if(visited[u] == true){
            color[i] != color[u];

            if (!isBipartite(adj,i,visited,color)){
                return false;
            }

            else if (color[i] == color[u])
                return false;
        }
    }
    return true;
}

int main(){
    int n = 6;

    vector<int> adj_list[n+1];
    vector<bool> visited(n+1);
    vector<int> color(n+1);


  addE(adj_list, 1, 2);
   addE(adj_list, 2, 3);
   addE(adj_list, 3, 4);
   addE(adj_list, 4, 5);
   addE(adj_list, 5, 6);
   addE(adj_list, 6, 1);
    
    visited[1] = true;
    color[1] = 0;

    cout << isBipartite(adj_list,0,visited,color);

    return 0;

}