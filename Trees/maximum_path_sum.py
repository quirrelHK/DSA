from representation import construct_tree


def find_max(node, maxx):
    if node is None: return 0
    
    left_sum = max(0,find_max(node.left,maxx))
    right_sum = max(0,find_max(node.right,maxx))
    
    maxx[0] = max(maxx[0], left_sum+right_sum+node.val)
    
    return node.val + max(left_sum,right_sum)

if __name__ == '__main__':
    arr = input().split()
    
    root = construct_tree(arr)
    
    maxx = [0]
    find_max(root,maxx)
    print(maxx)