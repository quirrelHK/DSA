# https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
from heapq import *

def bfs(src,dest,n,m,heights,dist):
    priority_q = [(0,src)]
    dist[src[0]][src[1]] = 0
    drow = [-1,0,1,0]
    dcol = [0,1,0,-1]
    while priority_q:
        diff,cell = heappop(priority_q)
        row,col = cell
        if row == dest[0] and col == dest[1]:
            return diff
        for i in range(4):
            nrow = row + drow[i]
            ncol = col + dcol[i]
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                new_effort = max(abs(heights[row][col] - heights[nrow][ncol]),diff)
                if new_effort < dist[nrow][ncol]:
                    dist[nrow][ncol] = new_effort
                    heappush(priority_q,(new_effort,(nrow,ncol)))
                    
    return -1
            

if __name__ == '__main__':
    heights = [
        [1,2,2],
        [3,8,2],
        [5,3,5]
        ]
    
    n,m = len(heights),len(heights[0])
    dist = [[float('inf')]*n for _ in range(m)]
    src = (0,0)
    dest = (n-1,m-1)
    
    print(bfs(src,dest,n,m,heights,dist))