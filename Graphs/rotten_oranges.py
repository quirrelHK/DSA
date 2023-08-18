# https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges


from collections import deque


def arrange_rotten(grid):
    tm = 0
    n,m = len(grid),len(grid[0])
    vis = [[0]*m for _ in range(n)]
    q = deque()
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 2:
                q.append((i,j,0))
                vis[i][j] = 2

    d_row = [-1,0,1,0]
    d_col = [0,1,0,-1]
    while q:
        row,col,t = q.popleft()
        tm = max(tm,t)
        for i in range(4):
            nrow = row + d_row[i]
            ncol = col + d_col[i]
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                if not vis[nrow][ncol] and grid[nrow][ncol] == 1:
                    vis[nrow][ncol]=2
                    grid[nrow][ncol]=2
                    q.append((nrow,ncol,t+1))

    for i in range(n):
        flag = True
        for j in range(m):
            if grid[i][j] == 1:
                tm = -1
                flag = False
                break
        if not flag: break
    
    return tm


if __name__ == '__main__':
    # grid = [[0,1,2],[0,1,2],[2,1,1]]
    grid = [[2,2,0,1]]

    print(arrange_rotten(grid))


