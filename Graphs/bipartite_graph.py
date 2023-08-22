# A bipartite graph is a graph, in which you can colour the entire graph using only 2 colours such that no two adjacent nodes have the same colour.
# Properties:
    # 1. Linear graphs with no cycle are always bipartite
    # 2. Any graph with only even length cycle is bipartite
    # 3. Any graph with any odd length cycle is bipartite
    
# Given a graph, check if it is bipartite or not
# TC: O(N+2E)
# SC: O(N)
from utils import list_graph
from collections import deque

def bfs(node,color,graph,vis):
    q = deque([node])
    vis[node]=color
    
    while q:
        node = q.popleft()
        
        for neighbour in graph[node]:
            if vis[neighbour] == -1:
                vis[neighbour] = 1 if vis[node] == 0 else 0
                q.append(neighbour)
            elif vis[neighbour] == vis[node]:
                return False
            
    return True
    
    

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    # 1 indexed
    graph = list_graph(v,e)
    
    # -1 -> not visited
    # 0 or 1 for colour
    vis = [-1]*(v+1)
    for i in range(1,v+1):
        if vis[i] == -1:
            if not bfs(i,0,graph,vis):
                print("Not bipartite")
                break
    else:
        print("Bipartite")
    