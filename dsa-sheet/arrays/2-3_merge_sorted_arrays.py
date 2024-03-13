# https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
import math

def swap_if_greater(arr1,arr2,ind1,ind2):
    if arr1[ind1] > arr2[ind2]:
        arr1[ind1],arr2[ind2] = arr2[ind2],arr1[ind1]
        
        
def merge_arrays(arr1,arr2,n,m):
    len = n+m
    gap = (len // 2) + (len % 2)
    
    while gap > 0:
        left = 0
        right = left + gap
        
        while right < len:
            
            if left < n and right >= n:
                swap_if_greater(arr1,arr2,left,right-n)
            elif left >= n:
                swap_if_greater(arr2,arr2,left-n,right-n)
            else:
                swap_if_greater(arr1,arr1,left,right)
            left += 1
            right += 1
            
        if gap == 1:
            break
            
        gap = (gap // 2) + (gap % 2)
        

if __name__ == '__main__':
    arr1 = list(map(int,input().split()))
    arr2 = list(map(int,input().split()))
    
    merge_arrays(arr1,arr2,len(arr1),len(arr2))
    print(arr1)
    print(arr2)