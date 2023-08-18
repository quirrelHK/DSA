# https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces

# Find the number of connected components in the graph
# TC: O(N) + O(V+2E) ~ O(N)
# SC: O(2N) ~ O(N)
from utils import list_graph
from collections import deque

def bfs(node,graph,vis):
    q = deque([node])
    vis[node] = 1
    while q:
        node = q.popleft()
        for neighbour in graph[node]:
            if not vis[neighbour]:
                q.append(neighbour)
                vis[neighbour]=1
    

if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    graph = list_graph(v,e)
    vis = [0]*(v+1)
    res = 0
    for i in range(1,v+1):
        if not vis[i]:
            res+=1
            bfs(i,graph,vis)

    print(res)
