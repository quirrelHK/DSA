# Given a binary tree, flatten it such that it represents a LL.
# You cannot create a new LL, you have to make changes to the original tree itself.
    #     1                              1
    #    / \                               \               
    #   2   5                  =>            2                       
    #  / \   \                                 \
    # 3   4   6                                  3
    #        /                                    \ 
    #       7                                       4
    #                                                \
    #                                                 5
    #                                                  \
    #                                                   6
    #                                                    \
    #                                                     7

# Using the concept of Morris traversal
# Optimal:
    # TC: O(N)
    # SC: O(1)
from representation import construct_tree

def flatten(root):
    if root is None: return None

    cur = root
    while cur:
        if cur.left:
            prev = cur.left
            while prev.right:
                prev = prev.right

            prev.right = cur.right
            cur.right = cur.left

        cur = cur.right
    return root

def traverse_flatten(root):
    if root is None: return None

    while root:
        print(root.val,end=' ')
        root = root.right
    

if __name__ == '__main__':
    arr = input().split()
    root = construct_tree(arr)

    root = flatten(root)
    traverse_flatten(root)