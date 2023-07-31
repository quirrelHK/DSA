# If the tree is a mirror of itself around the line through the centre
# If at any node, right child is equal to the left child then we can proceed; So, we will traverse the left and right subtrees simultaneously
# Left subtree pre-order; Right subtree reverse pre-order 

from representation import construct_tree

def helper(left,right):
    if left is None or right is None:
        return left == right
    
    if left.val != right.val:
        return False
    
    return helper(left.left, right.right) and helper(left.right, right.left)
    
    
def is_symmetric(root):
    if root is None: return None
    
    return helper(root.left,root.right)

if __name__ == '__main__':
    arr = input().split()
    
    root = construct_tree(arr)
    print(is_symmetric(root))