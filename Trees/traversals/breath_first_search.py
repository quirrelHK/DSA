from collections import deque
from representation import construct_tree
def level_order(root):
    if not root:
        print("None")
        return
    
    q=deque([root])
    
    while q:
        node=q.popleft()
        print(node.val)
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)
        # for i in range(len(q)):
        #     node=q.popleft()
        #     print(node.val)
        #     if node.left:
        #         q.append(node.left)
        #     if node.right:
        #         q.append(node.right)
            
            
if __name__=='__main__':
    arr=input().split()
    root=construct_tree(arr)
    
    level_order(root)
    