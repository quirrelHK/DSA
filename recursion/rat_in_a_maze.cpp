#include<bits/stdc++.h>
using namespace std;

void path(int i, int j, string move, vector<vector<int>> maze, vector<string> &ans,vector<vector<int>> &vis,int n){
    if(i == n-1 && j == n-1){   // when we have reached the (n-1,n-1)th cell
        ans.push_back(move);
    }

    //downward
    if(i+1<n && !vis[i+1][j] && maze[i+1][j] == 1){    // Boundary conditions, if current cell is not visited and next maze cell is available
        vis[i][j] = 1;
        path(i+1,j,move+"D",maze,ans,vis,n);
        vis[i][j] = 0;
    }

    //Leftward
      if(j-1>=0 && !vis[i][j-1] && maze[i][j-1] == 1){
        vis[i][j] = 1;
        path(i,j-1,move+"L",maze,ans,vis,n);
        vis[i][j] = 0;
    }

    //Rightward
      if(j+1<n && !vis[i][j+1] && maze[i][j+1] == 1){
        vis[i][j] = 1;
        path(i,j+1,move+"R",maze,ans,vis,n);
        vis[i][j] = 0;
    }

    //Upward
      if(i-1>=0 && !vis[i-1][j] && maze[i-1][j] == 1){
        vis[i][j] = 1;
        path(i-1,j,move+"U",maze,ans,vis,n);
        vis[i][j] = 0;
    }
}

// void path(int i, int j, string move, vector<vector<int>> maze, vector<string> &ans,vector<vector<int>> &vis,int n, int di[], int dj[]){
//     if(i == n-1 && j == n-1){
//         ans.push_back(move);
//         return;
//     }

//     string dir = "DLRU";   // for storing in lexiographical order 
//     for(int ind = 0; ind < 4; ++ind){
//         int nexti = i + di[ind];
//         int nextj = j + dj[ind];

//         if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && maze[nexti][nextj] == 1){
//             vis[i][j] = 1;
//             path(nexti,nextj,move+dir[ind],maze,ans,vis,n,di,dj);
//             vis[i][j] = 0;
//         }
//     }

// }

int main(){
    int n = 5;
    vector<vector<int>> maze = {{1,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,0,1,1,1}};
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<string> ans;

    
    int di[4] = {1,0,0,-1};   // di[0] and dj[0] give downward similar for other indices
    int dj[4] = {0,-1,1,0};
        
    // if(maze[0][0] == 1) path(0,0,"",maze,ans,vis,n,di,dj);

    if(maze[0][0] == 1) path(0,0,"",maze,ans,vis,n);
    for(int i = 0; i < ans.size(); ++i){
      cout << ans[i] << endl;
    }
    return 0;
}