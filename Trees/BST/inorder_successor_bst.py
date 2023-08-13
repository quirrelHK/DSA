from representation import construct_tree,convert_to_bst,inorder_traversal

def inroder_successor(root,target):
    if root is None: return None
    
    successor = None
    while root:
        if root.val <= target:
            root = root.right
        else:
            successor = root.val
            root = root.left
            
    return successor

if __name__ == '__main__':
    arr = input().split()
    target = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    res = inroder_successor(root,target)
    print(res)
    inorder_traversal(root)