# Given the root of a binary tree, return the size of the largest BST in the given tree if it exists
from representation import construct_tree,convert_to_bst

class NodeValue:
    def __init__(self,min_node,max_node,max_size):
        self.min_node = min_node
        self.max_node = max_node
        self.max_size = max_size

def find_largest_bst(root):
    if root is None:
        return NodeValue(int(1e9+7),-int(1e9+7),0)
    
    left = find_largest_bst(root.left)
    right = find_largest_bst(root.right)

    if left.max_node < root.val and root.val < right.min_node:
        return NodeValue(min(root.val,left.min_node),max(root.val,right.max_node),left.max_size+right.max_size+1)

    return NodeValue(-int(1e9+7),int(1e9+7),max(left.max_size,right.max_size))


if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)
    # root = convert_to_bst(root)

    res = find_largest_bst(root)
    print(res.max_size)
