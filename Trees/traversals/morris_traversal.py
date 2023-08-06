# Uses the concept of threaded binary tree. (inorder or preorder)
# The right most node in a subtree is connected to its parent node
# TC: O(N)
# SC: O(1)
from representation import construct_tree

def morris_traversal_inorder(root):
    inorder = []
    if root is None:
        return inorder
    cur = root
    while cur:
        if cur.left is None:
            inorder.append(cur.val)
            cur = cur.right
        else:
            prev = cur.left
            while prev.right and prev.right != cur:
                prev = prev.right
            
            if prev.right == None:
                prev.right = cur
                cur = cur.left
            else:
                prev.right = None
                inorder.append(cur.val)
                cur = cur.right
                
    return inorder

def morris_traversal_preorder(root):
    preorder = []
    if root is None: return preorder
    
    cur = root
    while cur:
        if cur.left is None:
            preorder.append(cur.val)
            cur = cur.right
        else:
            prev = cur.left
            while prev.right and prev.right != cur:
                prev = prev.right
            
            if prev.right is None:
                prev.right = cur
                preorder.append(cur.val)
                cur = cur.left
            else:
                prev.right = None
                cur = cur.right
    return preorder


if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)
    
    inorder = morris_traversal_inorder(root)
    print(*inorder)
    preorder = morris_traversal_preorder(root)
    print(*preorder)