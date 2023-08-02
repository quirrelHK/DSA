# You are given a target node and dist K; print all nodes that are at K distance from target
# The main problem is that we cannot travel to upper levels from target
# Approach:
    # 1. Do a level order traversal and mark the parent of the node(can be done using maps); makes it possible to move upwards. 
    # 2. Move radially outwards at a distance of one from the nodes and increment the distance variable (add all node visited node in a visited hash).
    # 3. Stop when distance k is reached

# TC: O(N); SC: O(N)
from representation import construct_tree
from collections import deque

def mark_parent(root):
    q = deque([root])
    mapp = dict()
    while q:
        
        node = q.popleft()
        
        if node.left: 
            mapp[node.left] = node
            q.append(node.left)
        if node.right:
            mapp[node.right] = node
            q.append(node.right)
                
    return mapp

def k_distance(root,k,target):
    if root is None: return None
    
    mapp = mark_parent(root)

    q = deque([target])
    vis = set()
    vis.add(target)
    dist = 0
    while q:
        size = len(q)
        if dist == k:
            break
        dist += 1
        for i in range(size):
            node = q.popleft()
            
            if node.left and node.left not in vis:
                vis.add(node.left)
                q.append(node.left)
            if node.right and node.right not in vis:
                vis.add(node.right)
                q.append(node.right)
            
            if mapp.get(node) and mapp.get(node) not in vis:
                vis.add(mapp[node])
                q.append(mapp[node])
    res = []
    for _ in range(len(q)):
        node = q.popleft()
        res.append(node.val)
    return res



if __name__ == '__main__':
    arr = input().split()
    k = int(input())
    root = construct_tree(arr)
    
    target = root.left
    res = k_distance(root,k,target)
    print(*res)                
    