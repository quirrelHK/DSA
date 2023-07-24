from collections import deque
class TreeNode:
    def __init__(self,val=-1) -> None:
        self.val = val
        self.left = None
        self.right = None
        
      
      
def helper(arr,i):
    root = None
    if i < len(arr):
        root = TreeNode(int(arr[i]))
        
        root.left = helper(arr,2*i+1)
        root.right = helper(arr,2*i+2)
        
    return root
  
def construct_tree(arr):
    if len(arr) == 0:
        return None
    
    return helper(arr,0)

def inorder(root):
    if root is None:
        return None
    
    inorder(root.left)
    print(root.val, end=' ')
    inorder(root.right)
 
 
def level_order(root):  
    if root is None:
        print("None")
        return
    
    q = deque([root])
    
    while q:
        node = q.popleft()
        print(node.val, end=' ')
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)
        
     

if __name__ == '__main__':
    arr = input().split()   # 1 2 3 4 5
    
    root = construct_tree(arr)
    print('Inorder:')
    inorder(root)
    print()
    print('Level Order:')
    level_order(root)
    
    
    
        
    