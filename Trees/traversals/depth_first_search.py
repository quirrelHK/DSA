# import sys
# sys.path.append('../Trees')
from representation import construct_tree


def inorder(root):
    if not root: return 
    
    inorder(root.left)
    print(root.val)
    inorder(root.right)     
    
def preorder(root):
    if not root: return
    
    print(root.val)
    preorder(root.left)
    preorder(root.right)
    
def postorder(root):
    if not root: return
    
    postorder(root.left)
    postorder(root.right)
    print(root.val)
    
    
arr=input().split()

root=construct_tree(arr)

print('Inorder:',end=' ')
inorder(root)

print('Preorder:',end=' ')
preorder(root)

print('Postorder:',end=' ')
postorder(root)

