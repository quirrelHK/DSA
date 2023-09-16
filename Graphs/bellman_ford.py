# TC: O(V*E)
# SC: O(V)

# Works for negative weights, does not give TLE like Dijkstra
# Can detect negative cycles
# Works for directed graphs, if undiredted graph give then make 2 edges i.e. u->v and v<-u

# Relax all the edges N-1 times, N is the no. of nodes.

def bellman_ford(src,n,edges,dist):
    dist[src] = 0
    
    for _ in range(n-1):
        for u,v,wt in edges:
            if dist[u] != float('inf') and dist[u] + wt < dist[v]:
                dist[v] = dist[u] + wt
                
    # Check of negative cycles; after N-1 relaxation the cost array should be relaxed. So, if it relaxes one more time then negative cycle exits
    for u,v,wt in edges:
        if dist[u] + wt < dist[v]:
            return -1
    return 0
        

if __name__ == '__main__':
    src = 0
    v,e = list(map(int,input().split()))
    edges = []
    for _ in range(e):
        x,y,wt = list(map(int,input().split()))
        edges.append((x,y,wt))
        
    dist = [float('inf')]*v 
    
    res = bellman_ford(src,v,edges,dist)
    if res == -1:
        print('Negative Cycle exists')
    else:
        print(dist)