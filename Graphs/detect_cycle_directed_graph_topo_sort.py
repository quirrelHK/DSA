# Intiution: Topological sort only works on DAG. If there is a cycle in the graph then the size of topo array would be less than no. of node.
# If there are no cycles then the size of topo array would be equal to the no. of nodes.

from utils import directed_list_graph
from collections import deque


def topo_sort(graph,v):
    
    topo = []
    indegree = [0]*(v+1)
    for i in range(v):
        for j in graph[i]:
            indegree[j]+=1
    # print(indegree)
    q = deque()
    for i in range(1,v):
        if indegree[i]==0:
            q.append(i)
    while q:
        node = q.popleft()
        topo.append(node)
        
        for neighbour in graph[node]:
            indegree[neighbour]-=1
            if indegree[neighbour]==0:
                q.append(neighbour)
    # print(topo)
    return not len(topo) == v

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = directed_list_graph(v,e,True)
    
    print(topo_sort(graph,v))
    