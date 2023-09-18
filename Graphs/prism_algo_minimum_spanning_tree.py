# https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
# Here we only require the weight of the minimum spanning tree. So, we don't need to store the parent in priority queue

from utils import weighted_list_graph
from heapq import *


def prims(v,graph,vis):
    priority_q = [(0,0)]    # wt,node
    sums = 0
    while priority_q:
        wt,node = heappop(priority_q)
        if vis[node] == 1:
            continue
        vis[node]=1
        sums += wt
        for adj_node,edge_wt in graph[node]:
            if not vis[adj_node]:
                heappush(priority_q,(edge_wt,adj_node))
    
    return sums
if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    graph = weighted_list_graph(v,e)
    
    vis = [0]*v
    
    print(prims(v,graph,vis))