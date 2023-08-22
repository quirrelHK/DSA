# TC: O(n*m*log(n*m))
# SC: O(n*m)

from utils import make_grid


def dfs(row,col,n,m,grid,vis,coordinates,row0,col0):
    vis[row][col] = 1
    coordinates.append((row-row0,col-col0))
    
    drow = [-1,0,1,0]
    dcol = [0,1,0,-1]
    for i in range(4):
        nrow = row + drow[i]
        ncol = col + dcol[i]
        if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and not vis[nrow][ncol] and grid[nrow][ncol] == 1:
            dfs(nrow,ncol,n,m,grid,vis,coordinates,row0,col0)

if __name__ == '__main__':
    n,m = list(map(int,input().split()))
    
    grid = make_grid(n,m)
    vis = [[0]*m for _ in range(n)]
    distinct = set()
    
    for i in range(n):
        for j in range(m):
            if not vis[i][j] and grid[i][j] == 1:
                coordinates = []
                dfs(i,j,n,m,grid,vis,coordinates,i,j)
                
                distinct.update(tuple(coordinates))
                
    print(len(distinct))
    
    
    
               