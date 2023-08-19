from utils import list_graph
from collections import deque

def is_cycle(node,graph,vis):
    q = deque([(node,-1)])
    vis[node]=1
    while q:
        node,parent = q.popleft()

        for neighbour in graph[node]:
            if not vis[neighbour]:
                vis[neighbour]=1
                q.append((neighbour,node))
            elif neighbour != parent:
                return True
            
    return False


if __name__ == '__main__':
    v,e = list(map(int,input().split()))
    # One indexed
    graph = list_graph(v,e)
    vis = [0]*(v+1)

    for i in range(1,v+1):
        if not vis[i]:
            if is_cycle(i,graph,vis):
                print('Cycle Exists')
                break

    else:
        print('Cycle does not exists')