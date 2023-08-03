# Given a binary tree find out the minimum time it requries to burn all the nodes from a given node.
# Just like nodes at distance K

# TC: O(N)
# SC: O(N)
from representation import construct_tree
from collections import deque

def mark_parent(root,start):
    mapp = dict()
    q = deque([root])
    start_node = None
    while q:
        size = len(q)
        
        for i in range(size):
            node = q.popleft()
            if node.val == start: start_node = node
            
            if node.left:
                mapp[node.left] = node
                q.append(node.left)
            if node.right:
                mapp[node.right] = node
                q.append(node.right)
    return start_node,mapp


def min_time(root,start):
    if root is None:
        return None
    
    start,parent = mark_parent(root,start)
    
    if start is None:
        return None
    res = 0
    vis = dict()
    
    q = deque([start])
    vis[start] = True
    
    while q:
        size = len(q)
        
        flag = False
        for i in range(size):
            node = q.popleft()
            
            if parent.get(node) and not vis.get(parent.get(node)):
                vis[parent.get(node)] = True
                q.append(parent.get(node))
                flag = True
            
            if node.left and not vis.get(node.left):
                vis[node.left] = True
                q.append(node.left)
                flag = True
            
            if node.right and not vis.get(node.right):
                vis[node.right] = True
                q.append(node.right)
                flag = True
            
        if flag:
            res += 1
            
    return res


if __name__ == '__main__':
    arr = input().split()
    start = int(input())
    root = construct_tree(arr)
    
    res = min_time(root,start)
    print(res)
    
                
                
            