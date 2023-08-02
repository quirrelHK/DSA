# Children sum property: the value of any node must be equal to the sum of the values of left and right child
# You are given any binary tree, convert it into a tree that follows children sum property
# You are not allowed to change the structure of the tree itself. However, you can change the value of nodes by only incrementing by one

# TC: O(N); SC: O(h) or O(N) if tree is skewed
from representation import construct_tree, levelorder_traversal

def chlidren_sum(root):
    if root is None: return None
    
    # Going downwards;
    # If parent is greater than the sum of children then increment the chlidren's values
    # If parent is smaller then the sum of children then increment the parent value
    # This ensures that while going backwards the value of parent is not greater than the sum of the children's value becuase then you cannot decrement the parent's value
    child = 0
    if root.left: child += root.left.val
    
    if root.right: child += root.right.val
    
    if root.val < child:
        root.val = child
    else:
        if root.left:
            root.left.val = root.val
        if root.right:
            root.right.val = root.val
            
    if root.left:
        chlidren_sum(root.left)
    if root.right:
        chlidren_sum(root.right)
        
    # Going upwards;
    # Add is values of children and increment the parent
    tot = 0
    if root.left: tot += root.left.val
    if root.right: tot += root.right.val
    
    if root.left or root.right: root.val = tot
    
    
if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)
    
    levelorder_traversal(root)
    chlidren_sum(root)
    levelorder_traversal(root)
    
