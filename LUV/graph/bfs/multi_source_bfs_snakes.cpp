// https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/

/* 
We will find the maximum value in the grid and run bfs from all these values simultaneously.
The maximum path(level) to reach the last node from all these sources is the shortest time.
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9+10;
int n,m;

int vis[N][N];
int level[N][N];
int val[N][N];

void reset(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            level[i][j]=INF;
            vis[i][j]=0;
        }
    }
}

bool isValid(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

vector<pair<int,int>> movements = {
    {1,0},{-1,0},{0,1},{0,-1},
    {1,1},{1,-1},{-1,1},{-1,-1}
};

int bfs(){
    int res=0;
    int maxx = -1;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            maxx = max(maxx,val[i][j]);
        }
    }

    queue<pair<int,int>> q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(val[i][j] == maxx){
                q.push({i,j});
                vis[i][j]=1;
                level[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        pair<int,int> cur_v = q.front();
        q.pop();
        int x = cur_v.first;
        int y = cur_v.second;

        for(auto &movement:movements){
            int child_x = movement.first+x;
            int child_y = movement.second+y;
            if(!isValid(child_x,child_y)) continue;
            if(vis[child_x][child_y]) continue;
            
            q.push({child_x,child_y});
            level[child_x][child_y]=level[x][y]+1;
            vis[child_x][child_y]=1;
            res = max(res,level[child_x][child_y]);
        }
    }
    return res;

}


int main(){
    int t;
    cin >> t;
    while(t--){
        reset();
        cin >> n >> m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> val[i][j];
            }
        }
        cout << bfs() << endl;
    }

}