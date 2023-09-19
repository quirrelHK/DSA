# https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

# TC: O(N^2)
# SC: O(N^2)

from utils import make_grid
from implement_DSU import DSU

if __name__ == '__main__':
    n,m = list(map(int,input().split()))
    grid = make_grid(n,m)
    
    ds = DSU(n*m)
    
    # Connect components
    for row in range(n):
        for col in range(m):
            if grid[row][col] == 0:
                continue
            drow = [-1,0,1,0]
            dcol = [0,-1,0,1]
            for i in range(4):
                nrow = row + drow[i]
                ncol = col + dcol[i]
                if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 1:
                    node_no = row*m + col
                    adj_node_no = nrow*m + ncol
                    ds.union_by_size(node_no,adj_node_no)
                
    maxx = 0               
    for row in range(n):
        for col in range(m):
            if grid[row][col] == 1:
                continue
            drow = [-1,0,1,0]
            dcol = [0,-1,0,1]
            components = set()
            for i in range(4):
                nrow = row + drow[i]
                ncol = col + dcol[i]
                if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                    if grid[nrow][ncol] == 1:
                        components.add(ds.find_parent(nrow*m + ncol))
            size = 0
            for component in components:
                size += ds.size[component]
            maxx = max(maxx,size + 1)
            
    for cell in range(n*m):
        maxx = max(maxx, ds.size[ds.find_parent(cell)])

    print(maxx)            
    
    
    
                                      
            
                    
                    