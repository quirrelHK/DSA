# https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

# Reverse the edges of the graph, then we can simply apply topo sort

from utils import directed_list_graph
from collections import deque

def find_safe_states(v,graph):
    indegree = [0]*v
    
    for i in range(v):
        for j in graph[i]:
            indegree[j]+=1
    q = deque()
    
    for i in range(v):
        if indegree[i]==0:
            q.append(i)
    topo = []     
    while q:
        node = q.popleft()
        topo.append(node)
        for neighbour in graph[node]:
            indegree[neighbour]-=1
            if indegree[neighbour]==0:
                q.append(neighbour)
                
    return sorted(topo)
    

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = directed_list_graph(v,e)
    
    rev_graph = [[] for _ in range(v)]
    for x in range(v):
        for y in graph[x]:
            rev_graph[y].append(x)
            
    res = find_safe_states(v,rev_graph)
    print(*res)

