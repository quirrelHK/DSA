class TreeNode:
    
    def __init__(self,val=0) -> None:
        self.val=val
        self.left=None
        self.right=None
    
    
'''
complete binary tree
'''     
def create_helper(arr,i):
    root = None
    # Base case for recursion
    if i < len(arr):
    
        root = TreeNode(int(arr[i]))
 
        # insert left child
        root.left = create_helper(arr, 2 * i + 1)
 
        # insert right child
        root.right = create_helper(arr, 2 * i + 2)
         
    return root
            
def construct_tree(arr):
    if len(arr)==0: return None
    
    return create_helper(arr,0)


def inorder_traversal(root:TreeNode) -> None:
    if not root: return None
    
    inorder_traversal(root.left)
    print(root.val,end=' ')
    inorder_traversal(root.right)
    
    
if __name__=='__main__':
    arr = input().split()

    root = construct_tree(arr)
    
    inorder_traversal(root)