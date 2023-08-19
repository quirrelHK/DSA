# https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1

from utils import make_grid
from collections import deque


def find_dist(n,m,grid):

    vis = [[0]*m for _ in range(n)]
    dist = [[0]*m for _ in range(n)]
    q = deque()
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                q.append((i,j,0))
                vis[i][j]=1
        

    drow = [-1,0,1,0]
    dcol = [0,1,0,-1]
    while q:
        row,col,step = q.popleft()
        dist[row][col] = step
        for i in range(4):
            nrow = row+drow[i]
            ncol= col+dcol[i]
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                if not vis[nrow][ncol]:

                    vis[nrow][ncol] = 1
                    q.append((nrow,ncol,step+1))
    return dist
        
if __name__ == '__main__':
    n,m = list(map(int,input().split()))
    grid = make_grid(n,m)

    dist = find_dist(n,m,grid)
    print(dist)


        