# Different than diameter of binary tree; here it means the max. no of nodes in a level between any two nodes
    #     1
    #    / \
    #   5   4   <- width = 2
    #  /     \
    # 6       8  <- width = 4; ans = 4
    
# Approach: index the binary tree then subtract the (first and last index) + 1; will give the width of that level
#           parent(i); leftChild(2*i+1), rightChild(2*i+2)
#           if tree is skeewed then overflow will occur. 
    #         0
    #        /
    #       1
    #      /
    #     3
    #    /
    #   7        
# 
# So we will reindex the nodes but sutracting the minInd from the curInd for each node at a particular level
    #     0
    #    / \
    #   0   1
    #  /     \
    # 0       4 (2*1+2)
    
from representation import construct_tree,TreeNode
from collections import deque


def width(root):
    if root is None:
        return root
    res = 0
    q = deque([(root,0)]) # node,index
    while q:
        size = len(q)
        _,min_ind = q[0]
        front,last=0,0
        
        for i in range(size):
             
            node,cur_ind = q.popleft()
            cur_ind-=min_ind
            if i==0:
                front = cur_ind
            if i==size-1:
                last = cur_ind
            if node.left:
                q.append((node.left,2*cur_ind+1))
            if node.right:
                q.append((node.right,2*cur_ind+2))
                
        res = max(res,last-front+1)
        
    return res

if __name__ == '__main__':
    # arr = input().split()
    # root = construct_tree(arr)
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.right = TreeNode(6)
    root.left.left = TreeNode(2)
    root.right.right = TreeNode(8)
    
    res = width(root)
    print(res)
                
            