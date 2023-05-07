from representation import construct_tree,TreeNode

def check_balanced(root):
    if not root:
        return -1
    
    left=check_balanced(root.left)
    if left==-1 and (root.left or root.right):
        return -1
    right=check_balanced(root.right)
    if right==-1 and (root.left or root.right):
        return -1
    
    if abs(left-right) > 1:
        return -1
    
    return 1 + max(left,right)

# arr=input().split()
# root=construct_tree(arr)

root=TreeNode(1)
root.left=TreeNode(2)
root.right=TreeNode(3)
root.left.left=TreeNode(4)
root.left.left.left=TreeNode(5)
print(True if check_balanced(root) != -1 else False)