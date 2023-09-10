# https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

# Djikstra's, in this particular problem we do not require a priority queue because from one adjacent node to another the cost is always one and the queue stores the data in a increasing/ascending order.

from utils import make_grid
from collections import deque

def bfs(row,col,src,dest,grid,dist):
    dist[src[0]][src[1]] = 0
    if src[0] == dest[0] and src[1] == dest[1]: return 0
    
    q = deque()
    q.append((0,src[0],src[1]))
    drow = [-1,0,1,0]
    dcol = [0,1,0,-1]
    while q:
        d,row,col = q.popleft()
        
        for i in range(4):
            nrow = row + drow[i]
            ncol = col + dcol[i]
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1 and d + 1 < dist[nrow][ncol]:
                if nrow == dest[0] and ncol == dest[1]:
                    return d+1
                dist[nrow][ncol] = d+1
                q.append((d+1,nrow,ncol))
                
    return -1
         

if __name__ == '__main__':
    n,m = list(map(int,input().split()))
    grid = make_grid(n,m)
    src = tuple(map(int,input().split()))
    dest = tuple(map(int,input().split()))
    
    dist = [[float('inf')]*m for _ in range(n)]
    
    print(bfs(n,m,src,dest,grid,dist))