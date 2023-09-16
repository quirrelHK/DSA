# https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
from heapq import *

def floyd_warshall(v,cost,threshold):
    
    for k in range(v):
        for i in range(v):
            for j in range(v):
                if cost[i][k] == float('inf') or cost[k][j] == float('inf'):
                    continue
                else:
                    cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j])
    max_neighbour = float('inf')
    city = -1

    for i in range(v):
        cnt=0
        for j in range(v):
            if cost[i][j] <= threshold:
                cnt+=1
        if cnt <= max_neighbour:
            max_neighbour = cnt
            city = i  
            
    return city

def dijkstra(v,edges,threshold):
    graph = [[] for _ in range(v)]
    for x,y,wt in edges:
        graph[x].append((y,wt))
        # graph[y].append((x,wt))
    # print(graph)
    max_neighbour = float('inf')
    city = -1
    q = []
    for k in range(v):
        cost = [float('inf')]*v
        cost[k] = 0
        heappush(q,(0,k))
        while q:
            dist,node = heappop(q)
            for adj_node,wt in graph[node]:
                if cost[node] + wt < cost[adj_node]:
                    cost[adj_node] = cost[node]+wt
                    heappush(q,(cost[adj_node],adj_node))
        cnt=0
        for i in range(v):
            if cost[i] <= threshold:
                cnt+=1
        if cnt <= max_neighbour:
            max_neighbour=cnt
            city = k

            
    return city
        

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    
    cost = []
    for i in range(v):
        lst = []
        for j in range(v):
            if i == j:
                lst.append(0)
            else:
                lst.append(float('inf'))
        cost.append(lst[:]) 
    edges = []
    for _ in range(e):
        x,y,wt = list(map(int,input().split()))
        edges.append((x,y,wt))
        edges.append((y,x,wt))
        cost[x][y]=wt
        cost[y][x]=wt
        
    threshold = int(input())
    print(dijkstra(v,edges,threshold))
    print(floyd_warshall(v,cost,threshold))