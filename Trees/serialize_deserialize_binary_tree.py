# Given the root of a binary tree; write a function to serialize the value of nodes in a string.
# Write another function the takes the serialized string as input and returns the root of the original tree.
from representation import construct_tree,TreeNode,levelorder_traversal
from collections import deque


def serialize(root):
    if root is None: return " "
    
    res = ''
    q = deque([root])
    while q:
        node = q.popleft()
        
        if node is None:
            res += '# '
            continue
        else:
            res += f'{node.val} '
        
        q.append(node.left)
        q.append(node.right)
        
    # print(res)        
    return res

def deserialize(string):
    if len(string) == 0: return None
    
    values = string.split()
    
    root = TreeNode(values[0])
    q = deque([root])
    i = 1
    while q:
        size = len(q)
        for _ in range(size):
            node = q.popleft()

            if values[i] != '#':
                node.left = TreeNode(values[i])
                q.append(node.left)
            i+=1
            if values[i] != '#':
                node.right = TreeNode(values[i])
                q.append(node.right)
            i+=1
            
    return root


if __name__ == '__main__':
    # arr = input().split()
    # root = construct_tree(arr)
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(3)
    root.right = TreeNode(4)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(6)
    levelorder_traversal(root)
    
    string = serialize(root)
    print(string)
    root = deserialize(string)
    levelorder_traversal(root)

