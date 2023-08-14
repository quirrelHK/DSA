# You are given a bst in which two nodes are swapped, you have to recover the original tree
# TC: O(N)
# SC: O(N)
from representation import construct_tree,convert_to_bst,TreeNode,inorder_traversal

class RecoverBST:
    
    def __init__(self) -> None:
        self.first = None
        self.prev = None
        self.middle = None
        self.last = None
        
    def inorder(self,root):
        if root is None: return
        
        self.inorder(root.left)
        
        if not self.prev is None and root.val < self.prev.val:
            
            # If 1st violation, then mark two nodes as first and middle
            if self.first is None:
                self.first = self.prev
                self.middle = root
            # If 2nd time violation, mark this as last
            else:
                self.last = root
                
        self.prev = root
        self.inorder(root.right)
        
    def recover_bst(self,root):
        self.first = self.middle = self.last = None   
        self.prev = None 

        self.inorder(root)
        
        if self.first and self.last:
            self.first.val,self.last.val = self.last.val,self.first.val
        elif self.first and self.middle:
            self.first.val,self.middle.val = self.middle.val,self.first.val
            
if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)
    root = convert_to_bst(root)
    root.left.val,root.right.left.val = root.right.left.val,root.left.val
    inorder_traversal(root)
    print()
    
    recover = RecoverBST()
    recover.recover_bst(root)
    inorder_traversal(root)
    
