# Doing anti-clockwise traversal of boundary

from representation import construct_tree


def isLeaf(node):
    return (node.left is None) and (node.right is None)

def addLeftBoundary(root,res):

    root = root.left
    while root:
        if not isLeaf(root):
            res.append(root.val)
        if root.left:
            root = root.left
        else:
            root = root.right
            
def addLeaves(root,res):

    if isLeaf(root):
        res.append(root.val)
        return
        
    if root.left: addLeaves(root.left,res)
    if root.right: addLeaves(root.right,res)
    
def addRightBoundary(root,res):

    root = root.right
    temp = []
    while root:
        if not isLeaf(root): temp.append(root.val)
        
        if root.right:
            root = root.right
        else:
            root = root.left
    
    for val in temp[::-1]:
        res.append(val)
        

if __name__ =='__main__':
    arr = input().split()
    root = construct_tree(arr)
    
    try:
        if root is None:
            print('None')
            raise ValueError('Root is None')
        else:
            res = [root.val]
            if not isLeaf(root):
                
                addLeftBoundary(root,res)
                addLeaves(root,res)
                addRightBoundary(root,res)
                
            print(res)
    except ValueError as e:
        print(e)
    
   
        