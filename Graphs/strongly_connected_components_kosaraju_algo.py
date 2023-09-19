# https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

# TC: O(V+E)
# SC: O(V+E)

# Kosaraju's algorithm
    # 1. Sort all the edges in acsending order of finishing time
    # 2. Reverse all the edges in the graph
    # 3. Apply dfs to all the components to find no. of SCC

from utils import directed_list_graph

def dfs(node,graph,vis,stack):
    vis[node] = 1
    
    for neighbour in graph[node]:
        if vis[neighbour] == 0:
            dfs(neighbour,graph,vis,stack)
            
    stack.append(node)

def dfs_t(node,graph,vis):
    vis[node] = 1

    for adj_node in graph[node]:
        if vis[adj_node] == 0:
            dfs_t(adj_node,graph,vis)

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    graph = directed_list_graph(v,e)    
    
    vis = [0]*v
    
    # sort nodes in ascending order of finishing time
    stack = []
    for i in range(v):
        if vis[i] == 0:
            dfs(i,graph,vis,stack)
            
    graph_t = [[] for _ in range(v)]
    
    for x in range(v):
        vis[x] = 0
        for y in graph[x]:
            graph_t[y].append(x)
            
            
    scc = 0
    
    while stack:
        node = stack.pop()
        if vis[node] == 0:
            dfs_t(node,graph_t,vis)
            scc += 1
    
    print(scc)
    