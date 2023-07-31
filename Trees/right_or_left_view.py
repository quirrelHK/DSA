# right view; reverse pre-order traversal
# left view; pre-order traversal
# using recursive approach SC:- O(h); using iterative SC:- O(N)

from representation import construct_tree
from collections import defaultdict,deque

def right_view(root,level,ds):
    if root is None:
        return
    
    if level == len(ds):    # First time comming to a level
        ds.append(root.val)
        
    right_view(root.right,level+1,ds)
    right_view(root.left,level+1,ds)
    
def left_view(root,level,ds):
    if root is None:
        return
    
    if level == len(ds):
        ds.append(root.val)
    left_view(root.left,level+1,ds)
    left_view(root.right,level+1,ds)        
    
    
if __name__ == '__main__':
    arr = input().split()
    
    root = construct_tree(arr)
    res = []
    right_view(root,0,res)
    print(res)
    
    
    res = []
    left_view(root,0,res)
    print(res)
    