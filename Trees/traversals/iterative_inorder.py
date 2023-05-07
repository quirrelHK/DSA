from representation import construct_tree

def iterative_inorder(root):
    if root is None:
        return []
    
    stack=[]
    inorder=[]
    node=root
    
    while True:
        if node is not None:
            stack.append(node)
            node=node.left
        else:
            if not stack: break
            
            node=stack.pop()
            inorder.append(node.val)
            node=node.right
    return inorder


arr=input().split()
root=construct_tree(arr)

inorder=iterative_inorder(root)

print(inorder)