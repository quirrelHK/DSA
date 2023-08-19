# https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-os-with-xs

def dfs(n,m,row,col,grid,vis):
    drow = [-1,0,1,0]
    dcol = [0,1,0,-1]
    vis[row][col] = 1

    for i in range(4):
        nrow = row+drow[i]
        ncol = col+dcol[i]
        if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
            if not vis[nrow][ncol] and grid[nrow][ncol] == 'O':
                dfs(n,m,nrow,ncol,grid,vis)


if __name__ == '__main__':
    # grid = [
    #     ['X', 'X', 'X', 'X'],
    #     ['X', 'O', 'X', 'X'],
    #     ['X', 'O', 'O', 'X'],
    #     ['X', 'O', 'X', 'X'],
    #     ['X', 'X', 'O', 'O']
    # ]

    grid = [
        ['X', 'O', 'X', 'X'],
        ['X', 'O', 'X', 'X'],
        ['X', 'O', 'O', 'X'],
        ['X', 'O', 'X', 'X'],
        ['X', 'X', 'O', 'O']
    ]


    n,m = len(grid),len(grid[0])
    vis = [[0]*m for _ in range(n)]
    
    # First row and last row
    for j in range(m):
        if grid[0][j] == 'O':
            dfs(n,m,0,j,grid,vis)
        if grid[n-1][j] == 'O':
            dfs(n,m,n-1,j,grid,vis)

    # First col and last col
    for i in range(n):
        if grid[i][0] == 'O':
            dfs(n,m,i,0,grid,vis)
        if grid[i][m-1] == 'O':
            dfs(n,m,i,m-1,grid,vis)

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'O' and not vis[i][j]:
                grid[i][j] = 'X'

    print(grid)        
