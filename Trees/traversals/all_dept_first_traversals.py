from representation import construct_tree,TreeNode

def traversals(root: TreeNode):
    if not root:
        return [],[],[]
    stack=[]
    pre,post,inorder=[],[],[]
    
    stack.append((root,1))
    
    while stack:
        node,num=stack.pop()
        
        if num==1:
            pre.append(node.val)
            num+=1
            stack.append((node,num))
            if node.left:
                stack.append((node.left,1))
        elif num==2:
            inorder.append(node.val)
            num+=1
            stack.append((node,num))
            if node.right:
                stack.append((node.right,1))
        else:
            post.append(node.val)
            
            
    return pre,post,inorder

arr=input().split()
root=construct_tree(arr)

preorder,postorder,inorder=traversals(root)

print('preorder',preorder)
print('inorder',inorder)
print('postorder',postorder)