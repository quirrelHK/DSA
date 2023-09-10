from utils import weighted_list_graph
from heapq import heappush,heappop

def bfs(src,dest,graph,dist,parent):
    dist[src]=0
    priority_q = [(0,src)]
    
    while priority_q:
        cost,node = heappop(priority_q)
        
        for adj_node, wt in graph[node]:
            if cost + wt < dist[adj_node]:
                dist[adj_node] = cost + wt
                parent[adj_node] = node
                heappush(priority_q,(dist[adj_node],adj_node))
                
    if dist[dest] == float('inf'):
        return [-1]
    
    node = dest
    res = [dest]
    while parent[node] != node:
        res.append(parent[node])
        node = parent[node]
        
    
    return res[::-1]


if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    graph = weighted_list_graph(v,e,is_one_indexed=True)
    src,dest = 1,v
        
    dist = [float('inf') for _ in range(v+1)]
    parent = [i for i in range(v+1)]
    
    res = bfs(src,dest,graph,dist,parent)
    print(*res)
    