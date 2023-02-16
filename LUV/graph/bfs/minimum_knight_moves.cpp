// https://www.spoj.com/problems/NAKANJ/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF = 1e9+7;

int vis[8][8];
int level[8][8];

int getX(string s){
    return s[0]-'a';
}

int getY(string s){
    return s[1]-'1';
}

bool isValid(int x, int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

void reset(){

    /* resets vis and level for each test case*/
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            vis[i][j]=0;
            level[i][j]=INF;
        }
    }
}

vector<pair<int,int>> movements = {
    /*
    vector of pairs denoting movemenst the horse can take from current cell
    */
    {2,-1},{2,1},
    {-2,-1},{-2,1},
    {-1,2},{1,2},
    {-1,-2},{1,-2}
};


int bfs(string source, string destination){
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destinationX = getX(destination);
    int destinationY = getY(destination);
    queue<pair<int,int>> q;   // For matrix type question, generally pair is involved
    
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1;
    level[sourceX][sourceY]=0;

    while(!q.empty()){
        pair<int,int> cur_vertex = q.front();
        int x=cur_vertex.first,y=cur_vertex.second;
        q.pop();
        for(auto movement: movements){
            int childX = movement.first+x;
            int childY = movement.second+y;

            if(!isValid(childX,childY)) continue;
            if(!vis[childX][childY]){
                q.push({childX,childY});
                vis[childX][childY]=1;
                level[childX][childY]=level[x][y]+1;
            }
        }
        if(level[destinationX][destinationY]!=INF){
            break;
        }
    }
    return level[destinationX][destinationY];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        reset();
        string s1,s2;
        cin >> s1 >> s2;
        cout << bfs(s1,s2) << endl;
    }
}