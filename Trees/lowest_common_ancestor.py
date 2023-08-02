# Brute force approach: find the path of the two target nodes; The last common node in both the paths will be the LCA
# TC: O(N), SC: O(2N)

# Optimal approach: using DFS traverse the tree, when a target node is found return it else return null; when both left and right returns not null at any node then that node is LCA
# TC: O(N), SC: O(N)

from representation import construct_tree


def lca(root,q,p):
    if root is None or root.val == q or root.val == p:
        return root
    
    left = lca(root.left,q,p)
    right = lca(root.right,q,p)
    
    if left is None:
        return right
    elif right is None:
        return left
    else:           # When both left and right are not NULL then we have found the LCA
        return root
    
if __name__ == '__main__':
    arr = input().split()
    q,p = map(int,input().split())
    root = construct_tree(arr)
    
    res = lca(root,q,p)
    
    if res is None:
        print(res)
    else:
        print(res.val)
    
