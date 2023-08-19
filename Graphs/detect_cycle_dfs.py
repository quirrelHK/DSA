from utils import list_graph


def is_cycle(node,parent,graph,vis):
    vis[node]=1

    for neighbour in graph[node]:
        if not vis[neighbour]:
            if is_cycle(neighbour,node,graph,vis):
                return True
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
            if is_cycle(i,-1,graph,vis):
                print('Cycle exists')
                break
    else:
        print('Cycle does not exists')
    