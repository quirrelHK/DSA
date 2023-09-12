# Using dijkstra's, the nodes will be from 0-99999

# https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
from collections import deque
MOD = int(1e5)
def bfs(start,end,arr,dist):
    dist[start]=0
    
    q = deque()
    q.append((0,start))
    
    while q:
        step,node = q.popleft()
        
        for i in range(len(arr)):
            val = (arr[i]*node)%MOD
            if step+1 < dist[val]:
                dist[val] = step+1
                if val == end:
                    return dist[val]
                q.append((step+1,val))
                
    return -1 if dist[end] == float('inf') else dist[end]
            
    
    

if __name__ == '__main__':
    start,end = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    
    dist = [float('inf') for _ in range(MOD)]
    
    print(bfs(start,end,arr,dist))
    