#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int, bool> visited;
        map<int, list<int>> adj;

        void addEdge(int u, int v){
            adj[u].push_back(v);
    }

    void DFS(int u){
        visited[u] = true;
        cout << u << " ";

        // list<int>::iterator i;
        // for(i = adj[u].begin(); i != adj[u].end(); ++i){
        for(auto i: adj[u]){
            if(!visited[i]){
                DFS(i);
            }
        }
    }
};

int main(){

    Graph g;
     g.addEdge(0,1);
    g.addEdge(4,2);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(0,5);
    g.addEdge(3,5);
    g.addEdge(5,0);
    // g.addEdge(1,4);

    // g.addEdge(0,1);

    cout << "DFS Traversal:\n";
    g.DFS(0);


    return 0;
}



