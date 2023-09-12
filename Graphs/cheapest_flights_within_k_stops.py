# https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

from collections import deque

def bfs(v,e,src,dest,graph,k):
    dist = [float('inf') for _ in range(v)]
    dist[src]=0
    q = deque()
    q.append((0,src,0)) # (stops,node,distance)
    while q:
        stops,node,cost = q.popleft()
        
        if stops > k:
            continue
        for adj_node,wt in graph[node]:
            
            if cost + wt < dist[adj_node] and stops <= k:
                dist[adj_node] = cost + wt
                q.append((stops+1,adj_node,dist[adj_node]))
                
    return -1 if dist[dest] == float('inf') else dist[dest]

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = [[] for _ in range(v)]
    
    for _ in range(e):
        x,y,wt = list(map(int,input().split()))
        graph[x].append((y,wt))
        
    k = int(input())
    src,dest = list(map(int,input().split()))
    
    print(bfs(v,e,src,dest,graph,k))