# https://practice.geeksforgeeks.org/problems/alien-dictionary/1

# In this particular case the answer always exits i.e. the dictionary (ordering) is always valid.
# There are 2 cases in which the order/dictionary is not possible
    # 1. abcd
    #    abc
    #   When nothing is left to compare and the smaller string comes after the larger string
    # 2. abc
    #    bat
    #    ade
    #   When there is a cyclic dependency


def topoSort(node,graph,vis,stack):
    vis[node] = 1
    for neighbour in graph[node]:
        if not vis[neighbour]:
            topoSort(neighbour,graph,vis,stack)
            
    stack.append(node)
    
def find_ordering(k,n,sorted_dict):
    graph =[[] for i in range(k)]

    for i in range(n-1):
        size = min(len(sorted_dict[i]),len(sorted_dict[i+1]))
        for j in range(size):
            if sorted_dict[i][j] != sorted_dict[i+1][j]:
                graph[ord(sorted_dict[i][j])-ord('a')].append(ord(sorted_dict[i+1][j]) - ord('a'))
                break
    
    vis = [0]*k
    res = []
    for i in range(k):
        if not vis[i]:
            topoSort(i,graph,vis,res)
            
    return res[::-1]     
    
if __name__ == '__main__':
    n,k = list(map(int,input().split()))
    
    sorted_dict = input().split()
    res = find_ordering(k,n,sorted_dict)
    strs = ''
    for val in res:
        strs += chr(val+ord('a'))
    print(*strs)
    
    