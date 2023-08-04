# The first node in the pre-order will always be the root of the tree.
# Then find the root in the in-order (using hashmap), then left to node will be leftSubtree of root and to the right will be rightSubtree
# Recursively apply this approch to all subtrees
from representation import TreeNode,levelorder_traversal


def helper_build_tree(inorder, in_start, in_end, preorder, pre_start, pre_end, inorder_mapp):
    if in_start > in_end or pre_start > pre_end: return None
    
    node = TreeNode(preorder[pre_start])
    
    in_ind = inorder_mapp[node.val]
    in_left = in_ind - in_start
    
    node.left = helper_build_tree(inorder,in_start,in_ind-1,preorder,pre_start+1,pre_start + in_left,inorder_mapp)
    node.right = helper_build_tree(inorder,in_ind+1,in_end,preorder,pre_start+in_left+1,pre_end,inorder_mapp)
    
    return node
    

def build_tree(inorder,preorder):
    if len(inorder) != len(preorder): return None
    
    inorder_map = {inorder[i]:i for i in range(len(inorder))}
    
    return helper_build_tree(inorder,0,len(inorder)-1,preorder,0,len(preorder)-1,inorder_map)


if __name__ == '__main__':
    inorder = list(map(int,input().split()))
    preorder = list(map(int,input().split()))
    
    root = build_tree(inorder,preorder)
    
    levelorder_traversal(root)