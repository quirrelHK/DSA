from representation import construct_tree,convert_to_bst,inorder_traversal

def find_kth_smallest(root,k,cnt):
    if root is None: return None
    
    l = find_kth_smallest(root.left,k,cnt)
    cnt[0]+=1
    if cnt[0] == k:
        return root.val
    r = find_kth_smallest(root.right,k,cnt)
    if l:
        return l
    if r:
        return r 

def count_elements(root,cnt):
    if root is None:
        return None
    cnt[0]+=1
    count_elements(root.left,cnt)
    count_elements(root.right,cnt)
    
    return cnt[0]

if __name__ == '__main__':
    arr = input().split()
    k = int(input())
    k_largest = int(input())
    root = construct_tree(arr)
    root = convert_to_bst(root)
    
    inorder_traversal(root)
    print()
    
    res = find_kth_smallest(root,k,[0])
    print(res)
    n = count_elements(root,[0])
    res = find_kth_smallest(root,n-k_largest+1,[0])
    print(res)
    
    