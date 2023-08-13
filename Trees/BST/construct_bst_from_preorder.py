
from representation import construct_tree,convert_to_bst,inorder_traversal,TreeNode



def construct_bst(arr,i,upper_limit):
   if i[0] == len(arr) or arr[i[0]] > upper_limit: return None
   
   root = TreeNode(arr[i[0]])
   i[0]+=1
   root.left = construct_bst(arr,i,root.val)
   root.right = construct_bst(arr,i,upper_limit)
   
   return root

def get_preorder_of_bst(root,arr):
   if root is None: return None
   
   arr.append(root.val)
   get_preorder_of_bst(root.left,arr)
   get_preorder_of_bst(root.right,arr)
   
   return arr

if __name__ == '__main__':

   arr = input().split()
   root = construct_tree(arr)
   root = convert_to_bst(root)
   preorder = get_preorder_of_bst(root,[])
   

   root = construct_bst(preorder,[0],float('inf'))
   inorder_traversal(root)
   # inorder_traversal(root)
   