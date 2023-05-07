# Longest path between any 2 nodes, the path does not have to go via the root node.

from representation import construct_tree

def find_diameter(root,res):
    if not root:
        return 0
    left=find_diameter(root.left,res)
    right=find_diameter(root.right,res)
    res[0]=max(res[0],left+right)
    
    return 1+max(left,right)

arr=input().split()
root=construct_tree(arr)
diameter=[-1]
find_diameter(root,diameter)
print(diameter)