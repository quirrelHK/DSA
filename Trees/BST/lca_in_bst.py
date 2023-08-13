from representation import construct_tree,convert_to_bst,preorder_traversal


def find_lca(root,u,v):
    if root is None: return None
    
    while root:
        if u < root.val and v < root.val:
            root = root.left
        elif u > root.val and v > root.val:
            root = root.right
        else:
            return root.val
        
    return root


if __name__ == '__main__':
    arr = input().split()
    u,v = list(map(int,input().split()))
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    res = find_lca(root,u,v)
    print(res)
    preorder_traversal(root)
    


