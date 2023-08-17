# You traverse one level at a time, from a starting node you traverse on level at a time, in a level you traverse all the nodes together then you move on the next level.
# You only traverse a node only once.
# Queue data structure is used
# TC: O(V+E)
# SC: O(3V)

from utils import generate_graph
from collections import deque

def bfs(vertices,graph,start):
    q = deque([start])
    vis = [0 for _ in range(vertices)]
    vis[start]=1

    res = []
    while q:
        node = q.popleft()
        res.append(node)
        for neighbour in graph[node]:
            if not vis[neighbour]:
                vis[neighbour]=1
                q.append(neighbour)

    return res

if __name__ == '__main__':
    graph,v,_ = generate_graph()
    res = bfs(v,graph,3)
    print(res)
