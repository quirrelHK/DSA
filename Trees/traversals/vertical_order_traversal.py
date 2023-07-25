from representation import construct_tree
from bisect import insort
from collections import deque,defaultdict

def vertical_view(root):
    if root is None:
        return None
    
    mapp = defaultdict(lambda : defaultdict(lambda : []))
    q = deque([(root,0,0)])
    
    while q:
        front = q.popleft()
        node,v,l = front
     
        insort(mapp[v][l],node.val)
        # mapp[v][l].append(node.val)
        
        if node.left:
            q.append((node.left,v-1,l+1))
        if node.right:
            q.append((node.right,v+1,l+1))
            
    ans = []
    for v in sorted(mapp.keys()):
        cols = []
        for l in sorted(mapp[v].keys()):
            cols.extend(mapp[v][l])
            
        ans.append(cols)
    
    return ans


if __name__ == '__main__':
    arr = input().split()
    
    root = construct_tree(arr)
    
    res = vertical_view(root)
    print(res)

            
        