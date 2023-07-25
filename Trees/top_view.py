from representation import construct_tree
from collections import deque

def top_view(root):
    if root is None:
        return None
    q = deque([(root,0)])
    
    mapp = dict()
    
    while q:
        node, vertical = q.popleft()
        
        if vertical not in mapp:
            mapp[vertical] = node.val
            
        if node.left:
            q.append((node.left,vertical-1))
        if node.right:
            q.append((node.right,vertical+1))
            
    res = []
    for key in sorted(mapp.keys()):
        res.append(mapp[key])
    
    return res


if __name__ == '__main__':
    arr = input().split()
    
    root = construct_tree(arr)
    res = top_view(root)
    
    print(res)
    