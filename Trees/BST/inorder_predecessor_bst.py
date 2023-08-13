from representation import construct_tree,convert_to_bst,inorder_traversal


def inorder_predecessor(root,target):
    if root is None: return None
    predecessor = None
    
    while root:
        if root.val >= target:
            root = root.left
        else:
            predecessor = root.val
            root = root.right
            
    return predecessor

if __name__ == '__main__':
    arr = input().split()
    target = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    res = inorder_predecessor(root,target)
    print(res)
    inorder_traversal(root)
    
    