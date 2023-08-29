from utils import directed_list_graph
from collections import deque

def topo_sort(v,graph):
    indegree = [0]*v
    
    for i in range(v):
        for node in graph[i]:
            indegree[node] += 1
    q = deque()
    
    for i,val in enumerate(indegree):
        if val == 0:
            q.append(i)
            
    res = []
    while q:
        node = q.popleft()
        res.append(node)
        
        for neighbour in graph[node]:
            indegree[neighbour]-=1
            if indegree[neighbour] == 0:
                q.append(neighbour)
                
    return res

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph = directed_list_graph(v,e)
    
    res = topo_sort(v,graph)
    
    print(res)
                
        
    