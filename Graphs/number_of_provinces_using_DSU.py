# https://practice.geeksforgeeks.org/problems/number-of-provinces/1

# Find number of connected components
from implement_DSU import DSU
from utils import make_grid

if __name__ == '__main__':
    n,m = list(map(int,input().split()))
    
    grid = make_grid(n,m)
    
    
    ds = DSU(n)
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 1:
                ds.union_by_size(i,j)
          
    cnt = 0
    for i in range(n):
        if i == ds.find_parent(i):
            cnt += 1
            
    print(cnt)