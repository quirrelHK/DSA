from representation import construct_tree,TreeNode


def find_height(root: TreeNode):
    if not root:
        return -1
    
    leftSubtree=find_height(root.left)
    rightSubtree=find_height(root.right)
    
    return 1 + max(leftSubtree,rightSubtree)

arr=input().split()
root=construct_tree(arr)

print(find_height(root.right))