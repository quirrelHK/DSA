# To check if a given BST is valid of not.
# Intution: for each node we will set a range, so for any particular node to be at the position it is, it should lie in the proper range.
# The range can be set based and parents value and the direction we are moving
# i.e if moving to left: (same as parent,parent val) or else if moving to right then (parent val,same as parent)

from representation import construct_tree,convert_to_bst

def is_valid_bst(root,min_val,max_val):
    if root is None: return True
    
    if root.val <= min_val or root.val >= max_val: return False
    
    return is_valid_bst(root.left,min_val,root.val) and is_valid_bst(root.right,root.val,max_val)


if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)
    minn,maxx = float('-inf'),float('inf')
    print(is_valid_bst(root,minn,maxx))
    root = convert_to_bst(root)
    print(is_valid_bst(root,minn,maxx))