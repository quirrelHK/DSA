#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int, bool> visited;
        map<int, list<int>> adj;

        void addEdge(int u, int v){
            adj[u].push_back(v);
    }

    void bfs(int s)
    {
        list<int> queue;
 
        visited[s] = true;
        queue.push_back(s);
    
        while(!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
    
        
            for (auto adjecent: adj[s])
            {
                if (!visited[adjecent])
                {
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
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

  
    cout << "BFS Traversal:\n";
    g.bfs(5);


    return 0;
}



