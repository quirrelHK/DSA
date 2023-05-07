from representation import construct_tree

def depth(root,node):
    if not root: return -1
    
    if root==node:
        return 0
    left=depth(root.left,node)
    right=depth(root.right,node)

    if left==-1 and right==-1:
        return -1
    
    return 1 + max(left,right)

arr=input().split()
root=construct_tree(arr)

print(depth(root,root.left.right))