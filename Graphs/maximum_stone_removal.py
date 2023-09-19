# https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

from implement_DSU import DSU
from utils import make_grid

if __name__ == '__main__':
    n,m = list(map(int,input().split()))
    grid = make_grid(n,m)
    
    stones = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                stones += 1
                
    ds = DSU(n+m)
    
    stone_nodes = dict()    # Only the nodes having stones will be stored
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                node_row = i
                node_col = j + n # j + (maxRow + 1)
                ds.union_by_size(node_row,node_col)
                stone_nodes[node_row] = 1
                stone_nodes[node_col] = 1 
                
                
    components = 0
    for k in stone_nodes.keys():
        if ds.find_parent(k) == k:
            components += 1
    
    print(stones - components)
            
    
                
    
    
    