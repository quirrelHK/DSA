# Using concept of vertical lines; the last node on vertical line will append
# If two nodes concide on an vertical then we will take the right node
# Cannot use recursive traversal because vertical line will get overwritten(have to use height to overcome that) 

from representation import construct_tree
from collections import deque,defaultdict


def bottom_view(root):
    res = []
    if root is None:
        return res
    
    mapp = defaultdict()
    q = deque([(root,0)])
    
    while q:
        node,vertical = q.popleft()
        
        mapp[vertical] = node.val
        
        if node.left:
            q.append((node.left,vertical-1))
            
        if node.right:
            q.append((node.right,vertical+1))
            
    
    for key in sorted(mapp.keys()):
        res.append(mapp[key])
        
    return res


if __name__ == '__main__':
    arr = input().split()
    
    root = construct_tree(arr)
    
    res = bottom_view(root)
    
    print(res)
    
    