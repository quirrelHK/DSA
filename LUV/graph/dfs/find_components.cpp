// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<int> graph[N];
bool vis[N];


// If we want to store the components
vector<vector<int>> connected_components;
vector<int> curr_connected_component;
void dfs(int vertex){
    curr_connected_component.push_back(vertex);
    vis[vertex]=true;
    for(int child:graph[vertex]){
        if(vis[child]) continue;
        
        dfs(child);
    }
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

    int cnt=0;
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        curr_connected_component.clear();
        dfs(i);
        connected_components.push_back(curr_connected_component);
        cnt++;
    }
    // cout << cnt <<  endl;
    for(auto &component: connected_components){
        for(int &vertex: component){
            cout << vertex << " ";
        }
        cout << endl;
    }
}