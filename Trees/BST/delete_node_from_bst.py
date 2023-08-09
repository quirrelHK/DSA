from representation import construct_tree,convert_to_bst,inorder_traversal


def detele_node(root,key):
    if root is None: return None
    
    if root.val == key:
        return helper(root)

    
    node = root
    while root:
        if root.val > key:
            if root.left and root.left.val == key:
                root.left = helper(root.left)
                break
                
            else:
                root = root.left
        else:
            if root.right and root.right.val == key:
                root.right = helper(root.right)
                break
            else:
                root = root.right
    else:
        return -1
    return node     
        

def helper(root):
    if root is None: return None
    
    if root.left is None:
        temp,root.right = root.right,None
        return temp
    
    elif root.right is None:
        temp,root.left = root.left,None
        return temp
    
    right_child,root.right = root.right,None
    last_child = find_last_child(root.left)
    last_child.right = right_child
    
    temp,root.left=root.left,None
    
    return temp

def find_last_child(root):
    if root.right is None: 
        return root
    
    return find_last_child(root.right)
    
    
    
if __name__ == '__main__':
    arr = input().split()
    target = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    inorder_traversal(root)
    print()
    node = detele_node(root,target)
    if node == -1: 
        print('Target not found')
    
    else: 
        inorder_traversal(node)   
    
    