# https://practice.geeksforgeeks.org/problems/topological-sort/1

# The nodes for which the dfs is completed, are pushed into the stack in that order. This way we can ensure that the linear ordering is followed.

# TC: O(N+2E)
# SC: O(N)

from utils import directed_list_graph


def dfs(node,graph,vis,stack):
    vis[node]=1
    for neighbour in graph[node]:
        if not vis[node]:
            dfs(neighbour,graph,vis,stack)
            
    stack.append(node)
    
def topo_sort(v,graph,vis):
    stack = []
    for i in range(v):
        if not vis[i]:
            dfs(i,graph,vis,stack)
            
    return stack[::-1]


if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = directed_list_graph(v,e,False)
    vis = [0]*v
    res = topo_sort(v,graph,vis)
    print(res)