# https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

# Kruskal's algorithm
    # 1. Sort all the edges by weight
    # 2. Apply DSU
    
    
# Here we only have to find the weight of the MST

# TC: O(V+E) + O(E*log(E))
# SC: O(V)

from utils import weighted_list_graph

class DSU:
    
    def __init__(self,n) -> None:
        self.parent = [i for i in range(n+1)]
        self.size = [1]*(n+1)
    
    def find_parent(self,u):
        if self.parent[u] == u:
            return u
        
        self.parent[u] = self.find_parent(self.parent[u])
        return self.parent[u]
    
    def union(self,u,v):
        prnt_u,prnt_v = self.find_parent(u),self.find_parent(v)
        if prnt_u == prnt_v:
            return
        if self.size[prnt_u] < self.size[prnt_v]:
            self.parent[prnt_u] = prnt_v
            self.size[prnt_v] += self.size[prnt_u]
        else:
            self.parent[prnt_v] = prnt_u
            self.size[prnt_u] += self.size[prnt_v]
if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    graph = weighted_list_graph(v,e)
    
    edges = []
    
    # The graph is undirected. So, we would have:
    # 1. 1 -> {2,5}
    # 2. 2 -> {1,5}
    # edges would have insert 2 edges. But the DSU would ignore it  
    for i in range(v):
        for adj_node,wt in graph[i]:
            node = i
            edges.append((wt,node,adj_node))
            
    edges.sort()
    mst_wt = 0
    dsu = DSU(v)
    for wt,x,y in edges:
        if dsu.find_parent(x) != dsu.find_parent(y):
            mst_wt += wt
            dsu.union(x,y)
            
    print(mst_wt)
    