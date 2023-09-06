# TC: O(N+E)
# SC: O(N)

from utils import list_graph
from collections import deque

def bfs(graph,src,dist):
    q = deque([src])
    dist[src] = 0
    
    while q:
        node = q.popleft()
        
        for neighbour in graph[node]:
            if dist[node]+1 < dist[neighbour]:
                dist[neighbour] = dist[node]+1
                q.append(neighbour)
                
                
    for i,val in enumerate(dist):
        if val == float('inf'):
            dist[i]=-1
            


if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = list_graph(v,e)
    src = int(input())
    dist = [float('inf') for _ in range(v)]
    
    bfs(graph,src,dist)
    print(dist)
    
    
