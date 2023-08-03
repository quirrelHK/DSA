# Given a complete binary tree count the number of nodes
# At max if the tree is completely filled; nodes = 2^h - 1 (where h is the height of the tree)
# But when the tree is not completely filled we cannot use this formula;
    #         1
    #        / \
    #       2    3
    #      / \  / \
    #     4   5 6  7
    #    / \ / \
    #   8  9 2  3     
    
# So if at any node if leftHeight != rightHeight; we will perform 1 + (nodes in Lsubtree) + (nodes in Rsubtree)
# Else if leftHeight == rightHeight; then simply for that subtree; 2^h - 1

# TC: O((logN)^2)
# SC: O(logN)
from representation import construct_tree

def find_left_height(node):
    height = 0
    while node:
        height += 1
        node = node.left
    return height

def find_right_height(node):
    height = 0
    while node:
        height += 1
        node = node.right
    return height


def count_nodes(root):
    # cnt = 0
    if root is None:
        return 0
    
    lh = find_left_height(root)
    rh = find_right_height(root)
    
    if lh == rh:
        return (1<<lh) - 1
        # cnt += (1<<lh) - 1
        # return cnt
    return 1 + count_nodes(root.left) + count_nodes(root.right)
    # cnt += 1 + count_nodes(root.left) + count_nodes(root.right)
    # return cnt

if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)
    
    res = count_nodes(root)
    print(res) 
    
    