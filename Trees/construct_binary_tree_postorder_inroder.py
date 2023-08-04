# The last node in the post-order will always be the root of the tree.
# Then find the root in the in-order (using hashmap), then left to node will be leftSubtree of root and to the right will be rightSubtree
# Recursively apply this approch to all subtrees
from representation import TreeNode, levelorder_traversal



def helper_build_tree(inorder, in_s, in_e, postorder, post_s, post_e, in_mapp):
    if in_s > in_e or post_s > post_e: return None
    
    node = TreeNode(postorder[post_e])
    in_ind = in_mapp[node.val]
    in_left = in_ind - in_s
    
    node.left = helper_build_tree(inorder, in_s, in_ind-1, postorder, post_s, post_s+in_left-1,in_mapp)
    node.right = helper_build_tree(inorder, in_ind+1, in_e, postorder, post_s+in_left, post_e-1,in_mapp)
    
    return node


def build_tree(inorder,postorder):
    if len(inorder) != len(postorder): return None
    
    mapp = {inorder[i]:i for i in range(len(inorder))}
    
    return helper_build_tree(inorder, 0, len(inorder)-1, postorder, 0, len(postorder)-1, mapp)

if __name__ == '__main__':
    inorder = list(map(int,input().split()))
    postorder = list(map(int,input().split()))
    
    root = build_tree(inorder,postorder)
    levelorder_traversal(root)