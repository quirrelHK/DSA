

def topo_sort(node,graph,vis,stack):
    vis[node]=1
    
    for neighbour,_ in graph[node]:
        # print(neighbour)
        if neighbour and not vis[neighbour]:
            topo_sort(neighbour,graph,vis,stack)
            
    stack.append(node)

if __name__ == '__main__':
    src = 0
    
    v,e = list(map(int,input().split()))
    
    graph = [[] for _ in range(v)]
    for _ in range(e):
        x,y,wt = list(map(int,input().split()))
        
        graph[x].append((y,wt))
    

    vis = [0]*v
 
    stack = []
    for i in range(v):
        if not vis[i]:
            topo_sort(i,graph,vis,stack)
    
    # The nodes that are not reachable from the source node; dist is "inf"
    for _ in range(v):
        if stack[-1] != src:
            stack.pop()
        
    dist = [float('inf') for _ in range(v)]
    dist[src]=0
    while stack:
        node = stack.pop()
        for v,wt in graph[node]:
            if dist[node] + wt < dist[v]:
                dist[v] = dist[node] + wt
    print(dist) 
    