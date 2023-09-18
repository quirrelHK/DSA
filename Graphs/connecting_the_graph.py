# https://practice.geeksforgeeks.org/problems/connecting-the-graph/1

from implement_DSU import DSU


if __name__ == '__main__':
    v,e = list(map(int,input().split()))

    ds = DSU(v)
    # edges = []
    extra_edges = 0
    for _ in range(e):
        x,y = list(map(int,input().split()))
        if ds.find_parent(x) == ds.find_parent(y):
            extra_edges += 1
        else:
            ds.union_by_size(x,y)
            
    components = 0
    for i in range(v):
        if i == ds.find_parent(i):
            components += 1
    
    if extra_edges >= components-1:
        print(components-1)
    else:
        print('-1')