# https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm
from collections import deque
from copy import deepcopy

# TC: O(N)
# SC: O(N^2)

def fill_color(sr,sc,new_colour,grid,vis):
    n,m = len(grid),len(grid[0])
    initial_color = grid[sr][sc]
    grid[sr][sc]=new_color
    q = deque([(sr,sc)])
    vis[sr][sc] = 1
    while q:
        row,col = q.popleft()
        d_rows = [-1,0,1,0]
        d_cols = [0,1,0,-1]
        for i in range(4):
            nrow = row + d_rows[i]
            ncol = col + d_cols[i]
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                if not vis[nrow][ncol] and grid[nrow][ncol] == initial_color:
                    vis[nrow][ncol]=1
                    grid[nrow][ncol]=new_colour
                    q.append((nrow,ncol))

    return grid


if __name__ == '__main__':
    grid = [[1,1,1],[1,1,0],[1,0,1]]
    sr,sc=0,0
    new_color = 2
    vis = [[0]*len(grid[0]) for _ in range(len(grid))]
    grid_copy = deepcopy(grid)
    grid_copy = fill_color(sr,sc,new_color,grid_copy,vis)
    print(grid_copy)


