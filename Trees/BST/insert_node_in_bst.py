from representation import construct_tree,convert_to_bst,TreeNode,inorder_traversal

def insert_node(root,val):
    if root is None:
        return TreeNode(val)
    
    cur = root
    while True:
        if cur.val <= val:
            if not cur.right is None:
                cur = cur.right
            else:
                cur.right = TreeNode(val)
                break
            
        else:
            if not cur.left is None:
                cur = cur.left
            else:
                cur.left = TreeNode(val)
                break
            
    return root

if __name__ == '__main__':
    arr = input().split()
    val = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    root = insert_node(root,val)
    inorder_traversal(root)
    
    
    