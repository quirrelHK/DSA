from representation import construct_tree
from collections import deque

def zig_zag(root):
    res = list()
    if root is None: return res
    
    q = deque([root])
    leftToRight = True
    
    while q:
        size = len(q)
        row = [0]*size
        
        for i in range(size):
            node = q.popleft()
            
            ind = i if leftToRight else size - i - 1
            row[ind] = node.val
        
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        res.append(row)
        leftToRight = (not leftToRight)
    return res
    

if __name__ == '__main__':
    arr = input().split()
    
    root = construct_tree(arr)
    res = zig_zag(root)
    print(res)