
def matrix_graph(vertices,edges,is_one_indexed=True):
    if is_one_indexed:
        graph  = [[0]*(vertices+1) for _ in range(vertices+1)]
    else:
        graph = [[0]*vertices for _ in range(vertices)]
    
    for _ in range(edges):
        u,v = list(map(int,input().split()))
        
        graph[u][v] = 1
        graph[v][u] = 1

    return graph

def list_graph(vetices,edges,is_one_indexed=True):
    if is_one_indexed:
        graph = [[] for i in range(vetices+1)]
    else:
        graph = [[] for i in range(vetices)]
    
    for _ in range(edges):
        u,v = list(map(int,input().split()))
        graph[u].append(v)
        graph[v].append(u)

    return graph

def weighted_list_graph(vetices,edges,is_one_indexed=True):
    if is_one_indexed:
        graph = [[] for i in range(vetices+1)]
    else:
        graph = [[] for i in range(vetices)]
    
    for _ in range(edges):
        u,v,w = list(map(int,input().split()))

        graph[u].append((v,w))
        graph[v].append((u,w))

    return graph


def directed_list_graph(vetices,edges,is_one_indexed=True):
    if is_one_indexed:
        graph = [[] for i in range(vetices+1)]
    else:
        graph = [[] for i in range(vetices)]
    
    for _ in range(edges):
        u,v = list(map(int,input().split()))

        graph[u].append(v)

    return graph

def generate_graph():
    # One based
    v,e = 8,8
    graph = [[] for i in range(v)]
    graph[0].append(1)
    graph[0].append(2)
    graph[1].append(4)
    graph[1].append(5)
    graph[2].append(3)
    graph[2].append(6)
    graph[3].append(7)
    graph[6].append(7)

    graph[1].append(0)
    graph[2].append(0)
    graph[4].append(1)
    graph[5].append(1)
    graph[3].append(2)
    graph[6].append(2)
    graph[7].append(3)
    graph[7].append(6)

    return graph,v,e

def make_grid(n,m):
    grid = [[0]*m for _ in range(n)]
    cells = int(input())
    for _ in range(cells):
        row,col = list(map(int,input().split()))
        grid[row][col] = 1
    return grid