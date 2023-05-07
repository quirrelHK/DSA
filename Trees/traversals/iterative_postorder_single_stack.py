from representation import construct_tree

def postorder_traversal(root):
    if root is None: return None
    stack=[]
    postorder=[]
    
    while root or stack:
        if root:
            stack.append(root)
            root=root.left          # 1st all left nodes
        else:
            temp = stack[-1].right  
            if temp is None:             # 3rd after left and right then node # top ka right
                temp=stack.pop()
                postorder.append(temp.val)
                while stack and temp==stack[-1].right:
                    temp=stack.pop()
                    postorder.append(temp.val)
            else:
                root=temp        # 2nd all right nodes
                
    return postorder
    

arr=input().split()
root=construct_tree(arr)

postorder=postorder_traversal(root)
print(postorder)