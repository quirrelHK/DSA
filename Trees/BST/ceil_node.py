# Givne a key, find the lowest node value that is greater than or equeal to keu value
from representation import construct_tree,convert_to_bst


def ceil_value(root,key):
    ceil = -1
    if root is None:
        return ceil
    
    while root:
        if root.val == key:
            return root.val
        
        if root.val > key:
            ceil = root.val
            root = root.left
        else:
            root = root.right
            
    return ceil

if __name__ == '__main__':
    arr = input().split()
    key = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    res = ceil_value(root,key)
    print(res)
    
    
        