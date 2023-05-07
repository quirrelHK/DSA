from representation import construct_tree


def iterative_preorder(root):
    if root is None:
        return []
    inorder=[]
    node=root
    stack=[]
    stack.append(node)
    
    while stack:
        top=stack.pop()
        inorder.append(top.val)
        
        if top.right:
            stack.append(top.right)
        if top.left:
            stack.append(top.left)
            
    return inorder


arr=input().split()
root=construct_tree(arr)

inorder=iterative_preorder(root)

print(inorder)