# https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
from heapq import *
from utils import weighted_list_graph
MOD = int(1e9+7)

def bfs(src,dest,graph,dist,ways):
    dist[src]=0
    ways[src]=1
    q = []
    q.append((0,src))
    while q:
        cost,node = heappop(q)
        
        for adj_node,wt in graph[node]:
            # First time we are arriving with this distance 
            if cost + wt < dist[adj_node]:
                dist[adj_node] = cost + wt
                ways[adj_node] = ways[node]
                heappush(q,(cost+wt,adj_node))
            elif cost + wt == dist[adj_node]:
                ways[adj_node] = (ways[adj_node] + ways[node])%MOD
    
    return -1 if dist[dest] == float('inf') else ways[dest]
                

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    graph = weighted_list_graph(v,e)
    src,dest = list(map(int,input().split()))
    

    dist = [float('inf')]*v
    ways = [0]*v
    
    print(bfs(src,dest,graph,dist,ways))
    
    
    