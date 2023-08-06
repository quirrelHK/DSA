from representation import construct_tree,convert_to_bst


def find_node(root,val):
    while not root is None and root.val != val:
        root = root.left if val < root.val else root.right
        
    return root

if __name__ == '__main__':
    arr = input().split()
    node = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    res = find_node(root,node)
    print(res.val)