# https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

# TC: O(N^2)
# SC: O(N^2)
from utils import make_grid
from collections import deque


def bfs(row,col,grid,n,m,vis):
    q = deque([(row,col)])
    vis[row][col]=1

    while q:
        row,col = q.popleft()

        for del_r in range(-1,2):
            for del_c in range(-1,2):
                nrow = row+del_r
                ncol = col+del_c
                if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                    if not vis[nrow][ncol] and grid[nrow][ncol] == 1:
                        vis[nrow][ncol] = 1
                        q.append((nrow,ncol))

if __name__ == '__main__':
    n = int(input())
    m = int(input())
    grid = make_grid(n,m)
    res = 0
    vis = [[0]*m for _ in range(n)]
    for row in range(n):
        for col in range(m):
            if not vis[row][col] and grid[row][col] == 1:
                bfs(row,col,grid,n,m,vis)
                res+=1

    print(res)