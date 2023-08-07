# Given a key, find the largest node value that is smaller than or equal to key value
from representation import construct_tree,convert_to_bst

def floor_val(root,key):
    floor = -1
    if root is None:
        return floor
    
    while root:
        if root.val == key:
            floor = root.val
            return floor
        
        if root.val < key:
            floor = root.val
            root = root.right
        else:
            root = root.right
            
    return floor


if __name__ == '__main__':
    arr = input().split()
    key = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    res = floor_val(root,key)
    print(res)