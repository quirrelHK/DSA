# https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
from utils import directed_list_graph

def dfs(node,graph,vis,path_vis,check):
    vis[node]=1
    path_vis[node]=1
    check[node]=0
    for neighbour in graph[node]:
        if not vis[neighbour]:
            if dfs(neighbour,graph,vis,path_vis,check) == True:
                return True
        elif path_vis[neighbour]==1:
            check[neighbour]=0
            return True
        
    check[node]=1
    path_vis[node]=0
    return False
    
    
    
if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    graph = directed_list_graph(v,e,False)
    
    vis = [0]*v
    path_vis = [0]*v
    check = [0]*v
    
    for i in range(v):
        if not vis[i]:
            dfs(i,graph,vis,path_vis,check)
            
    res = []
    for i in range(v):
        if check[i] == 1:
            res.append(i)
    print(res)