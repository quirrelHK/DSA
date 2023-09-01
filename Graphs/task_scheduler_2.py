# https://practice.geeksforgeeks.org/problems/course-schedule/1
# The order of doing tasks is reversed.

# Using topological sort

from collections import deque


def task_scheduler(v,graph):
    indegree = [0]*v
    
    for i in range(v):
        for j in graph[i]:
            indegree[j]+=1
            
    q = deque()
    for i in range(v):
        if indegree[i]==0:
            q.append(i)
            
    topo=[]
    while q:
        node = q.popleft()
        topo.append(node)
        
        for neighbour in graph[node]:
            indegree[neighbour]-=1
            if indegree[neighbour]==0:
                q.append(neighbour)
    return topo if len(topo) == v else []

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    graph =[[] for _ in range(v)]
    
    for _ in range(e):
        x,y = list(map(int,input().split()))
        graph[y].append(x)
        
    print(task_scheduler(v,graph))
    
    