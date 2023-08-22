from utils import directed_list_graph


def dfs(node,graph,vis,path_vis):
    vis[node]=1
    path_vis[node]=1
    
    for neighbour in graph[node]:
        if not vis[neighbour]:
            if dfs(neighbour,graph,vis,path_vis) == True:
                return True
        elif path_vis[neighbour] == 1:
            return True
    path_vis[node]=0
    
    return False
    


if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = directed_list_graph(v,e)
    vis = [0]*(v+1)
    path_vis = [0]*(v+1)
    
    for i in range(1,v+1):
        if not vis[i]:
            if dfs(i,graph,vis,path_vis):
                print("Cycle exists")
                break
    else:
        print("Cycle does not exists")
    