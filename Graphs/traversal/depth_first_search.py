# We recursively traverse the graph to its depth, if we cannot traverse further i.e. no unvisited node, then we backtrack
# TC: O(V+E)
# SC: O(3V)

from utils import generate_graph

def dfs(node,graph,vis,res):
    res.append(node)
    vis[node] = 1
    for neighbour in graph[node]:
        if not vis[neighbour]:
            dfs(neighbour,graph,vis,res)


if __name__ == '__main__':
    graph,v,_ = generate_graph()
    res = []
    vis = [0]*v
    dfs(2,graph,vis,res)
    print(res)
