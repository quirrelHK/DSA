# https://leetcode.com/problems/critical-connections-in-a-network/description/

# TC: O(V+E)
# SC: O(V+E)

timer = 1

def dfs(node,parent,vis,graph,tn,low,bridges):
    global timer
    vis[node] = 1
    tn[node] = low[node] = timer
    timer += 1

    for adj in graph[node]:
        if adj == parent: continue
        if vis[adj] == 0:
            dfs(adj,node,vis,graph,tn,low,bridges)
            low[node] = min(low[node],low[adj])
            
            if low[adj] > tn[node]:
                bridges.append((node,adj))
        else:
            low[node] = min(low[node],low[adj])

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    edges = []
    for _ in range(e):
        x,y = list(map(int,input().split()))
        edges.append((x,y))
        
    graph = [[] for _ in range(v)]
    for x,y in edges:
        graph[x].append(y)
        graph[y].append(x)
        

    vis = [0]*v
    
    # Insertion time
    tn = [0]*v
    # Lowest time of insertion
    low = [0]*v
    
    bridges = []
    for i in range(v):
        if vis[i] == 0:
            dfs(i,-1,vis,graph,tn,low,bridges)
            
    print(*bridges)
   