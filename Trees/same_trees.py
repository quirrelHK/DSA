from representation import construct_tree


def isSame(node1, node2):
    if node1 is None or node2 is None:
        return node1 == node2
    
    return node1.val == node2.val and isSame(node1.left,node2.left) and isSame(node1.right,node2.right)

if __name__ == '__main__':
    arr1 = input().split()
    arr2 = input().split()
    
    root1 = construct_tree(arr1)
    root2 = construct_tree(arr2)
    
    print(isSame(root1,root2))