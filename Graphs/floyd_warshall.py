# Multi path algorithm

# Works for negative weights
# Detect negative cycles; if after relaxation there is negative cost in node to node i.e. [i][i] then negative cycle exits

# TC: O(V^3)
# SC: O(V^2)

# If there are no negative weights then we can use Dijkstra, apply it for all individual nodes

def floyd_warshall(v,cost):
    
    for k in range(v):  # via node k for each iteration; cost[i][j]=cost[i][k]+cost[k][j] i.e. going from node i to node j though node k
        for i in range(v):
            for j in range(v):
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])
    
    # Detect negative cycles
    for i in range(v):
        if cost[i][i] < 0:
            return -1
    return 0
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
        cost[x][y] = wt

    res = floyd_warshall(v,cost)
    
    if res == -1:
        print('Negative Cycle exits')
    else:
        print(cost)        
    
      
           