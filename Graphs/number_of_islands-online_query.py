# https://practice.geeksforgeeks.org/problems/number-of-islands/1

from implement_DSU import DSU


if __name__ == '__main__':
    n,m = list(map(int,input().split()))
    k = int(input())
    
    ds = DSU(n*m)
    vis = [[0]*m for _ in range(n)]
    cnt = 0
    res = []
    while k:
        k-=1
        row,col = list(map(int,input().split()))
        if vis[row][col] == 1:
            res.append(cnt)
            continue
        vis[row][col] = 1
        cnt += 1
        
        drow = [-1,0,1,0]
        dcol = [0,1,0,-1]
        for i in range(4):
            nrow = row + drow[i]
            ncol = col + dcol[i]
            
            if nrow >= 0 and nrow < n and ncol >= 0 and ncol < m:
                if vis[nrow][ncol] == 1:
                    node_no = row*m + col
                    adj_node_no = nrow*m + ncol
                    if ds.find_parent(node_no) != ds.find_parent(adj_node_no):
                        cnt -= 1
                        ds.union_by_size(node_no,adj_node_no)
                        
        res.append(cnt)
        
    print(*res)