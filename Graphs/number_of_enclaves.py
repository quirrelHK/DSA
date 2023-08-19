# https://practice.geeksforgeeks.org/problems/number-of-enclaves/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-enclaves

from utils import make_grid
from collections import deque

def dfs(q,grid,n,m,vis):
    drow = [-1,0,1,0]
    dcol = [0,-1,0,1]
    while q:
        row,col = q.popleft()
        for i in range(4):
            nrow = row+drow[i]
            ncol = col+dcol[i]
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                if not vis[nrow][ncol] and grid[nrow][ncol] == 1:
                    vis[nrow][ncol]=1
                    q.append((nrow,ncol))


if __name__ == '__main__':
    n,m = list(map(int,input().split()))

    grid = make_grid(n,m)
    vis = [[0]*m for _ in range(n)]
    q = deque()
    for j in range(m):
        if grid[0][j] == 1:
            vis[0][j]=1
            q.append((0,j))
        if grid[n-1][j] == 1:
            vis[n-1][j]=1
            q.append((n-1,j))
    
    for i in range(n):
        if grid[i][0] == 1:
            vis[i][0]=1
            q.append((i,0))
        if grid[i][m-1] == 1:
            vis[i][m-1]=1
            q.append((i,m-1))

    cnt = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1 and not vis[i][j]:
                cnt += 1
    print(cnt)
