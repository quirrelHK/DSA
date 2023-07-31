# Inorder traversal; append to ds on is not the target node
#  We traverse left, come back (pop from ds), then right

from representation import construct_tree

def helper(root,x,ds):
    if root is None:
        return False
    
    ds.append(root.val)
    if root.val == x: return True
    
    if helper(root.left,x,ds) or helper(root.right,x,ds):
        return True
    
    ds.pop()
    return False
        
def find_path(root,x):
    ds = []
    if root is None: return ds
    
    helper(root,x,ds)
    return ds

if __name__ == '__main__':
    arr = input().split()
    node = int(input())
    root = construct_tree(arr)
    print(find_path(root,node))
    
        
        
        