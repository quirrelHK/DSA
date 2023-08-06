from collections import deque
class TreeNode:
    
    def __init__(self,val=0) -> None:
        self.val=int(val)
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
    
    
def preorder_traversal(root:TreeNode) -> None:
    if root is None: return None

    print(root.val, end=' ')
    preorder_traversal(root.left)
    preorder_traversal(root.right)
    
def postorder_traversal(root:TreeNode) -> None:
    if root is None: return None
    
    postorder_traversal(root.left)
    postorder_traversal(root.right)
    print(root.val,end=' ')
    
def levelorder_traversal(root:TreeNode) -> None:
    if root is None: return None
    
    q = deque([root])
    while q:
        size = len(q)
        for i in range(size):
            node = q.popleft()
            print(node.val,end=' ')
            
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    print()
        
    
            
def convert_to_bst(root):
    if root is None: return None
    inorder_arr = []
    
    def inorder(root):
        if root is None: return
        
        inorder(root.left)
        inorder_arr.append(root)
        inorder(root.right)
    
    inorder(root)
    inorder_arr.sort(key = lambda node:node.val)
    
    def construct_bst(start,end):
        if start > end: return None
        
        mid = (start+end)>>1
        node = inorder_arr[mid]
        node.left = construct_bst(start,mid-1)
        node.right = construct_bst(mid+1,end)
        
        return node
    
    root = construct_bst(0,len(inorder_arr)-1)
    return root
    # print([node.val for node in inorder_arr])
if __name__=='__main__':
    arr = input().split()

    root = construct_tree(arr)
    root = convert_to_bst(root)
    inorder_traversal(root)
    print()
    # levelorder_traversal(root)
    # print()
    # preorder_traversal(root)