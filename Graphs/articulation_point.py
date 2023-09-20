# https://practice.geeksforgeeks.org/problems/articulation-point-1/1

# TC: O(V+E)
# SC: O(V+E)

from utils import list_graph


timer = 1
def dfs(node,parent,graph,vis,tin,low,marked):
    global timer
    vis[node] = 1
    tin[node] = low[node] = timer
    timer += 1
    
    child = 0
    for adj in graph[node]:
        if adj == parent:
            continue
        if vis[adj] == 0:
            dfs(adj,node,graph,vis,tin,low,marked)
            low[adj] = min(tin[node],low[adj])
            
            if low[adj] >= tin[node] and parent != -1:
                marked[node] = 1
            child += 1
        else:
            # If it is visited then you cannot take low of anyone before it, because after removing it you might not reach the low
            low[node] = min(low[node],tin[adj])
            
            
    # If starting point has multiple components
    if child > 1 and parent == -1:
        marked[node] = 1
    
if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = list_graph(v,e)
    vis = [0]*v
    tin = [0]*v
    low = [0]*v
    
    marked = [0]*v
    
    ans = []
    
    for i in range(v):
        if vis[i] == 0:
            dfs(i,-1,graph,vis,tin,low,marked)
            
    for i in range(v):
        if marked[i] == 1:
            ans.append(i)
            
    print(*ans) 
    