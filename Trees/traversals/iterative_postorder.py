from representation import construct_tree

def iterative_postorder(root):
    if not root:
        return []
    stack_1,stack_2=[],[]
    postorder=[]
    node=root
    stack_1.append(node)
    
    while stack_1:
        node=stack_1.pop()
        stack_2.append(node.val)
        
        if node.left:
            stack_1.append(node.left)
        if node.right:
            stack_1.append(node.right)
            
    while stack_2:
        postorder.append(stack_2.pop())
            
    return postorder




arr = input().split()
root=construct_tree(arr)

postorder=iterative_postorder(root)

print(postorder)