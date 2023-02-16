// https://www.codechef.com/problems/REVERSE

/*
We use bfs to find shortest path between any two nodes, but weight of all the edges should be same. If not 
then we can use Dijkstra.

We can use 0-1 bfs to find shortest path, if all the edges have only two type of weights (generally either 0 or 1)
At any time there are only two types of levels in the queue. While processing current level the previous would have
been popped from the queue.
So, we say there are only x and x+1 level in the queue at any time.
If we encounter a node with weight=1 we push it to the back. But if we encounter a node with weight=0 we push
to the front of the queue
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+7;
int n,m;

vector<pair<int,int>> g[N];   // For weighed graphs Ex: g[1] = {node,weight}
vector<int> level(N,INF);

int dfs(){
    deque<int> q;

    q.push_back(1);  // Source
    level[1]=0;
    while(!q.empty()){
        int cur_vertex = q.front();
        q.pop_front();

        for(auto &child: g[cur_vertex]){
            int child_vertex = child.first;
            int wt = child.second;

            if(level[cur_vertex]+wt < level[child_vertex]){
                level[child_vertex]=level[cur_vertex]+wt;

                if(wt==1){
                    q.push_back(child_vertex);
                }
                else{
                    q.push_front(child_vertex);
                }
            }
        }

    }
    return level[n]==INF ? -1 : level[n];
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int x,y;
        cin >> x >> y;
        if(x==y) continue;  // Self edges
        g[x].push_back({y,0});
        g[y].push_back({x,1});  // reverse edge
    }

    cout << dfs() << endl;
}