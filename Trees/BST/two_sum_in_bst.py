# We will use the concept of BST iterator for the optimal appraoch.
# We will add one from function to the BstIterator i.e. before(), it will give us the largest element and decrement, or we can use 2 BST iterator 1 for forward and 1 for reverse. 
# Then for the inorder: 1 2 4 5 6 7 8 9, we will have a next() that gives the smallest and a before() that gives the largest.
# A value k is given, you have to find whether there exists two nodes whose sum in equal to k

from representation import construct_tree,convert_to_bst,TreeNode

# TC: O(N)
# SC: O(H)
class BstIterator:
   
    
    # reverse = True -> before()
    # reverse = False -> next()
    # reverse = True
    
    def __init__(self,root,is_reversed) -> None:
        self.reverse = is_reversed
        self.__stack = []
        self.__push_all(root)
        
    def has_next(self):
        return not len(self.__stack)==0
    
    def next(self):
        temp = self.__stack.pop()
        if not self.reverse:
            self.__push_all(temp.right)
        else:
            self.__push_all(temp.left)
            
        return temp.val
    
    def __push_all(self,node:TreeNode):
        while node:
            self.__stack.append(node)
            if self.reverse==True:
                node = node.right
            else:
                node = node.left
                
def find_target(root,k):
    if root is None: return False
 
    left = BstIterator(root,False)
    right = BstIterator(root,True)
    
    i=left.next()
    j=right.next()
    while i< j:
        if i+j==k:  return True
        elif i+j < k: i = left.next()
        else: j = right.next()
    return False    


if __name__ == '__main__':
    arr = input().split()
    k = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    print(find_target(root,k))
    
    
    