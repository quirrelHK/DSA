# Using min. Heap or Priority queue

# TC: O(V*logE)
# SC: O(N)
from utils import weighted_list_graph
import heapq
from random import randint
def bfs(src,graph,dist):
    dist[src]=0
    priority_q = [(0,src)]
    while priority_q:

        cost,node = heapq.heappop(priority_q)
        for adj_node,wt in graph[node]:
            if cost + wt < dist[adj_node]:
                dist[adj_node] = cost + wt
                heapq.heappush(priority_q,(dist[adj_node],adj_node))
                
                
    
    
    

if __name__ == '__main__':
    src = 0
    v,e = list(map(int,input().split()))
    graph = weighted_list_graph(v,e)
    dist = [float('inf') for _ in range(v)]
    
    bfs(src,graph,dist)
    print(dist)
    

    
    
