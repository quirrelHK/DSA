# TC ~ O(1); there will the N nodes for N calls, so overall TC is constant
# SC: O(H)

from representation import construct_tree,convert_to_bst,TreeNode
from collections import deque


class BstIterator:
    
    # When we reach a new node push all the elements in the left
    def __init__(self,root:TreeNode) -> None:
        self.__stack = deque()
        self.__push_all(root)
    
    def has_next(self):
        return not len(self.__stack)==0
    
    # Print the smallest node i.e. top of the stack, go to right and apply push_all()
    def next(self)->int:
        temp = self.__stack.pop()
        self.__push_all(temp.right)
        return temp.val
    
    def  __push_all(self,node:TreeNode)->None:
        while node:
            self.__stack.append(node)
            node = node.left
            
if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    iterator = BstIterator(root)
    print(iterator.next())
    print(iterator.next())
    print(iterator.next())
    print(iterator.has_next())
    print(iterator.next())
    print(iterator.next())
    print(iterator.next())
    print(iterator.next())
    print(iterator.has_next())
    print(iterator.next())
    print(iterator.has_next())
    
        
    